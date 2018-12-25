import json
import uuid


# 传入解码后的json文件，返回一个字符串数组，其中的每一个元素都是一个function
def get_functions(file_content):
    functions = []                           # 存储返回的字符串数组
    tokens = file_content['tokens']          # 存储所有读取的token

    # 当读到'FunctionDecl'类型的token时，开始加入元素，同时记录'{'和'}'的匹配情况，
    # 如果完全匹配，则调用get_function函数得到一个字符串结果
    index = 0
    while index < len(tokens):
        # 当读到'FunctionDecl'类型的token时，开始加入元素
        willBreak = False        # 判断是否需要跳出外层循环
        if tokens[index]['sem'] == 'FunctionDecl':
            temp_tokens = []

            # 去除简单的函数声明
            # 如果是形如'int func(int, int);'的函数声明，需要去掉，这里假设符号的sem属性为'FunctionDecl'
            # 先一口气扫描到')'，然后判断下一个字符是不是'{'，如果是，则进行函数分割；反之，说明是形如上面提到的函数声明，干掉
            index2 = index
            while index2 < len(tokens):
                current_token = tokens[index2]
                if current_token['text'] == ')' and current_token['sem'] == 'FunctionDecl':
                    break
                index2 += 1
            # 如果下一个是'{'的话，就不做处理；否则，就跳过
            if index2 < len(tokens) - 1 and tokens[index2 + 1]['text'] != '{':
                index = index2 + 1
                continue

            # 进行正常的函数分割
            left_brace_num = 0
            right_brace_num = 0
            index2 = index
            while index2 < len(tokens):
                current_token = tokens[index2]
                if current_token['text'] == '{':
                    left_brace_num += 1
                elif current_token['text'] == '}':
                    right_brace_num += 1
                    if left_brace_num == right_brace_num:
                        break
                temp_tokens.append(current_token)
                index2 += 1

            # 将得到的分割好的token序列
            functions.append(get_function(temp_tokens))
            index = index2 + 1
            print(temp_tokens)
        else:
            index += 1

    return functions


# 传入上一步切割好的token数组，返回一个字符串，为一个function
def get_function(tokens):
    fixed_word = ['pthread_mutex_lock','pthread_mutex_unlock','pthread_cond_wait','pthread_cond_signal']
    struct_strings = []
    result_function = ''            # 最后返回的处理好的一个函数
    head_String = ''
    C_String = ''
    entity_counter = 1              # 计数，用来替换变量名，格式entity_i
    line_num = tokens[0]['line']    # 记录当前的行号，用来进行换行操作
    formals = []
    variable_match = {}
    i=0
    useless_words = ['static','unsinged','!']
    keywords = ['pthread_mutex_lock','pthread_mutex_unlock','pthread_cond_signal','NULL','malloc','free','sizeof','pthread_cond_wait','pthread_mutex_t','pthread_cond_t','i','strcpy','strncpy','pthread_mutex','pthread_t']
    while(i<len(tokens)):
        if tokens[i]['text'] in useless_words:
            i+=1
            continue
        if tokens[i]['text']=='long':
            if tokens[i+1]['text']=='long':
                i+=2
            else:
                i+=1
            C_String = C_String +" "+"int"+" "
        if tokens[i]['line'] > line_num:
            line_num = tokens[i]['line']
            C_String += '\n'
        if tokens[i]['sem']=='StructDecl' and tokens[i]['text']=='struct':
            struct_string = ''
            if tokens[i+1]['text'] in keywords:
                while tokens[i]['line'] == tokens[i +1]['line']:
                    i += 1
            else:
                struct_string = struct_string+' '+tokens[i]['text']
                while tokens[i]['line']==tokens[i+1]['line']:
                    i+=1
                    struct_string = struct_string + " "+tokens[i]['text']
                #i+=1
                #struct_string = struct_string + " "+ tokens[i]['text']
                struct_strings.append(struct_string)
        elif tokens[i]['text']=='return':
            while tokens[i]['text'] != ';':
                i += 1
        elif tokens[i]['text']=='}' and i==len(tokens)-1:
            i+=1
            continue
        elif tokens[i]['kind'] == 'Keyword' and tokens[i]['sem'] == 'FunctionDecl':
            if tokens[i+1]['text'] in fixed_word:
                while tokens[i]['line']==tokens[i+1]['line']:
                    i+=1
            else:
                bracket_counter = 0
                while tokens[i]['text']!= '(':
                    i+=1
                    if tokens[i]['text']== '(':
                        bracket_counter+=1
                i+=1
                while bracket_counter!=0:
                    if tokens[i]['kind'] == 'Identifier' and tokens[i]['sem'] == "ParmDecl":
                        variable_match[tokens[i]['text']] = "var_" + str(entity_counter)
                        entity_counter += 1
                        variable_name = tokens[i]['sym']['type'] + " " + variable_match[tokens[i]['text']]
                        formals.append(variable_name)  # formals 后面再处理
                    if tokens[i]['text']== '(':
                        bracket_counter+=1
                    elif  tokens[i]['text']== ')':
                        bracket_counter -= 1
                    i+=1
                if tokens[i]['text']== ';':
                    i+=1
        elif tokens[i]['text'] in keywords:
            C_String = C_String + " "+  tokens[i]['text']
        # 收集函数参数，将其作为函数开始后的变量声明
        elif tokens[i]['text']=="{" and tokens[i-1]['sem']=='FunctionDecl':
            i+=1
            continue
        elif tokens[i]['sem'] == "ParmDecl" or tokens[i]['sem']=='FunctionDecl':
            i+=1                              # 函数参数中其他部分直接忽略
            continue
        # 形如 int i = foo()形式的，直接将foo()替换为rand()
        elif tokens[i]['kind'] == 'Identifier' and tokens[i-1]['text'] == '=' \
                and tokens[i-2]['kind'] == 'Identifier' and tokens[i]['sem'] == 'DeclRefExpr' and (tokens[i]['sym']['kind']=='FunctionDecl'):
            if 'sym' in tokens[i] and tokens[i]['sym'] != None:
                C_String = C_String + "rand();"
                i+=1
                while tokens[i]['text']!=';':    # 遇到;作为结束标志
                    i+=1
        # 处理形如while(foo()) while(!foo()) if(foo()) if(!foo())形式
        elif tokens[i]['kind'] == 'Identifier' and (tokens[i-1]['text'] == '('or tokens[i-1]['text'] == '!') and tokens[i-1]['sem']!='FunctionDecl'\
                and (tokens[i-1]['sem'] == 'IfStmt' or tokens[i-1]['sem'] == 'WhileStmt'or tokens[i-1]['sem']=='DeclRefExpr' or tokens[i-1]['sem']=='UnaryOperator')\
                and ('sym' in tokens[i] and tokens[i]['sym']['kind']!=None and tokens[i]['sym']['kind']=='FunctionDecl'):
                print(tokens[i]['text'])
                C_String = C_String + "rand()"
                counter = 1
                while counter!=0:       #防止多个括号的出现 如 foo(foo()) 取最后一个括号
                    i+=1
                    if tokens[i]['text']=='(':
                        counter+=1
                    elif tokens[i]['text']==')':
                        counter-=1
                C_String = C_String + ")"
        # 对于这样foo()独占一行的函数，直接去掉
        elif tokens[i]['kind'] == 'Identifier' and tokens[i]['sem']=='DeclRefExpr' and tokens[i]['line']>tokens[i-1]['line'] :
            if 'sym' in tokens[i] and tokens[i]['sym']!=None and tokens[i]['sym']['kind']=='FunctionDecl':
                if tokens[i-1]['text'] != '(' and tokens[i-1]['text'] != '=':
                    i += 1
                    while tokens[i]['text'] != ';':
                        i += 1
            else:
                if tokens[i]['text'] in variable_match:
                    C_String = C_String + " "+variable_match[tokens[i]['text']] + " "
                else:
                    variable_match[tokens[i]['text']] = "var_" + str(entity_counter)
                    entity_counter += 1
                    C_String = C_String  + " "+variable_match[tokens[i]['text']] + " "
        # 变量命名映射
        elif tokens[i]['kind'] == 'Identifier':
            if tokens[i]['text'] in variable_match:
                C_String = C_String  + " "+ variable_match[tokens[i]['text']] + " "
            else:
                variable_match[tokens[i]['text']] = "var_" + str(entity_counter)
                entity_counter += 1
                C_String = C_String  + " "+ variable_match[tokens[i]['text']] + " "
        # 其他的正常打印输出
        else:
            C_String = C_String  + " "+ tokens[i]['text'] + " "
        i+=1
    for formal in formals:
        formal_string = ''
        # char[] 和 int[]
        if '[' in formal and ']' in formal:
            if 'char' in formal:
                formal_string = 'char ' + formal[formal.index(']') + 1:] + '[10];'
            elif 'int' in formal:
                formal_string = 'int ' + formal[formal.index(']') + 1:] + '[10];'
        elif '*' in formal:
            if 'char' in formal:
                formal_string = 'char ' + formal[formal.index('var'):] + '[10];'
            elif 'int' in formal:
                formal_string = 'int ' + formal[formal.index('var'):] + '[10];'
            elif 'void' in formal:
                formal_string = 'void*' + formal[formal.index('var'):] + ';'
        # char 与 int类型
        else:
            if 'char' in formal:
                formal_string = 'char ' + formal[formal.index('var'):] + '=\'a\';'
            elif 'int' in formal:
                formal_string = 'const int ' + formal[formal.index('var'):] + '=10;'
        head_String = head_String + formal_string + '\n'

    return head_String + C_String,struct_strings


if __name__ == '__main__':
    file = open('malloc_free_2.c.tok', errors='ignore')
    file_content = json.loads(file.read())
    tokens = file_content['tokens']  # 存储所有读取的token
    #result = get_functions(file_content)
    function,struct_strings = get_function(tokens)
    struct = ''
    for string in struct_strings:
        struct = struct + string+'\n'
    head_file = open('head.txt', errors='ignore')
    head_string = head_file.read()
    function = head_string+'\n'+struct+"int main(){\n" + function + "\nreturn 0;\n}"
    result = ''
    for i in range(0,len(function)):
        if function[i]=='\n' and function[i+1]!='\n':
            result+=function[i]
        elif function[i]!='\n':
            result += function[i]
    f = open(str(uuid.uuid1()) + '.c', errors='ignore', mode='w')
    f.write(result)
    """
    for function in result:
        function = "#include<stdlib.h> \nint main(){\n"+function+"\nreturn 0;\n}"
        f = open(str(uuid.uuid1())+'.c', errors='ignore',mode='w')
        f.write(function)
        # print(function)
        # print('-----------------------------')
"""
