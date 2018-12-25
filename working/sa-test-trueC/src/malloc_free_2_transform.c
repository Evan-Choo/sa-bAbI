#include <stdlib.h> // Tag.OTHER
#include <string.h> // Tag.OTHER
struct pthread_mutex_t{ int i; };// Tag.OTHER
struct pthread_cond_t{ int i; };  // Tag.OTHER
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; }   // Tag.OTHER
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; } // Tag.OTHER
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t); // Tag.OTHER
void pthread_cond_signal(struct pthread_cond_t* cond_t);// Tag.OTHER
int main()// Tag.OTHER
{// Tag.OTHER
 const  int  var_4  =  10  ; // Tag.BODY
 char  *  var_5  ; // Tag.BODY
 var_5  =  malloc (  var_4  )  ; // Tag.BODY
 var_5  =  "0"  ; // Tag.MEMORY_MANAGEMENT_SAFE
 free (  var_5  )  ; // Tag.BODY
return 0;// Tag.BODY
}// Tag.OTHER