#include <stdlib.h>                                                                     
#include <string.h>                                                                     
struct pthread_mutex_t{ int i; };                                                      
struct pthread_cond_t{ int i; };                                                       
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; }                    
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; }                
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t); 
void pthread_cond_signal(struct pthread_cond_t* cond_t);
int main(){
int var_1=rand();
char  var_2[10];
 const  int  var_3  =  128  ; 
 char  var_4  [  25  ]  ,  var_5  [  ]  =  "result.txt"  ,  var_6  [  var_3  ]  ,  *  var_7  , 
 var_8  [  100  ]  [  40  ]  =  {  {  '0'  }  }  ; 
 const  char  var_9  [  ]  =  " .,;:!-\n\t"  ; 
 int  var_10  [  100  ]  =  {  0  }  ,  i ,  var_11  =  0  ,  var_12  =  0  ,  var_13  =  0  ,  var_14  =  0  ; 
 if  (  var_1  >  1  )  { 
 strncpy (  var_4  ,  var_2  [  1  ]  ,  sizeof (  var_4  )  )  ; 
 }  else  { 
 } 
return 0;
}
