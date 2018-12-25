#include <stdlib.h>                                                                     
#include <string.h>                                                                     
struct pthread_mutex_t{ int i; };                                                      
struct pthread_cond_t{ int i; };                                                       
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; }                    
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; }                
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t); 
void pthread_cond_signal(struct pthread_cond_t* cond_t);
 struct pthread_t { };
 struct pthread_mutex { };
 struct list { };
int main(){
const int var_1=10;
void*var_2;
void*var_3;
void*var_4;
 const  int  var_5  =  100  ; 
 static  struct  pthread_t  var_7  [  var_5  ]  ; 
 static  struct  pthread_mutex_t var_8  [  var_5  ]  ; 
 static  struct  pthread_cond_t var_9  [  var_5  ]  ; 
 static  struct  pthread_cond_t var_10  [  var_5  ]  ; 
 static  struct  pthread_mutex  *  var_12  [  var_5  ]  ; 
 static  unsigned  long  long  var_13  [  var_5  ]  ; 
 pthread_mutex_lock (  &  var_8  [  var_1  ]  )  ; 
 var_13  [  var_1  ]  ++  ; 
 pthread_mutex_unlock (  &  var_8  [  var_1  ]  )  ; 
 pthread_cond_signal (  &  var_9  [  var_1  ]  )  ; 
return 0;
}
