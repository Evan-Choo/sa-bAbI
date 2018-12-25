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
 const  int  var_2  =  100  ; 
 static  unsigned  long  long  var_3  [  var_2  ]  ; 
 static  struct  pthread_mutex_t var_4  [  var_2  ]  ; 
 static  struct  pthread_cond_t var_5  [  var_2  ]  ; 
 unsigned  long  long  var_6  ; 
 pthread_mutex_lock (  &  var_4  [  var_1  ]  )  ; 
 var_6  =  var_3  [  var_1  ]  ; 
 while  (  1  )  { 
 pthread_cond_wait (  &  var_5  [  var_1  ]  ,  &  var_4  [  var_1  ]  )  ; 
 var_6  =  var_3  [  var_1  ]  ; 
 } 
 pthread_mutex_unlock (  &  var_4  [  var_1  ]  )  ; 
return 0;
}
