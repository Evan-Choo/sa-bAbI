#include <stdlib.h>                                                                     
#include <string.h>                                                                     
struct pthread_mutex_t{ int i; };                                                      
struct pthread_cond_t{ int i; };                                                       
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; }                    
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; }                
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t); 
void pthread_cond_signal(struct pthread_cond_t* cond_t);
struct var_1  {
 int  var_2  ;
 char  *  var_3  ;
 }  var_1;
int main(){
 struct  var_1  *  var_4  =  malloc (  16  )  ; 
 if  (  !  var_4  ) 
 if  (  !  var_4  ->  var_3  )  { 
 free (  var_4  )  ; 
 var_4  ->  var_3  =  malloc (  8  )  ; 
 } 
return 0;
}
