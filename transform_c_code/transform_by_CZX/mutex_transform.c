#include <stdlib.h>                                                                     
#include <string.h>                                                                     
struct pthread_mutex_t{ int i; };                                                      
struct pthread_cond_t{ int i; };                                                       
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; }                    
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; }                
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t); 
void pthread_cond_signal(struct pthread_cond_t* cond_t);
int main(){
const int var_1=10;
 const  int  var_2  =  100  ; 
 static  struct  pthread_mutex_t var_3  [  var_2  ]  ; 
 static  unsigned  long  long  var_4  [  var_2  ]  ; 
 unsigned  long  long  var_5  ; 
 pthread_mutex_lock (  &  var_3  [  var_1  ]  )  ; 
 var_5  =  var_4  [  var_1  ]  ; 
 pthread_mutex_unlock (  &  var_3  [  var_1  ]  )  ; 
return 0;
}
