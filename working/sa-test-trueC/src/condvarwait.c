#include <stdlib.h> // Tag.OTHER
#include <string.h>// Tag.OTHER
struct var_1 { int var_2 ; } ;// Tag.OTHER
struct var_3 { int var_2 ; } ;// Tag.OTHER
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; } // Tag.OTHER
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; } // Tag.OTHER
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t); // Tag.OTHER
void pthread_cond_signal(struct pthread_cond_t* cond_t);// Tag.OTHER
int main() // Tag.OTHER
{// Tag.OTHER
int var_4 = 10 ;// Tag.BODY
const int var_5 = 100 ; // Tag.BODY
int var_6 [ var_5 ] ; // Tag.BODY
struct var_1 var_7 [ var_5 ] ; // Tag.BODY
struct var_3 var_8 [ var_5 ] ; // Tag.BODY
int var_9 ; // Tag.BODY
pthread_mutex_lock ( & var_7 [ var_4 ] ) ; // Tag.BODY
var_9 = var_6 [ var_4 ] ; // Tag.BODY
if ( !(var_9 == 0) ) { // Tag.BODY
pthread_cond_wait ( & var_8 [ var_4 ] , & var_7 [ var_4 ] ) ; // Tag.COND_WAIT_UNSAFE
var_9 = var_6 [ var_4 ] ; // Tag.BODY
} // Tag.BODY
pthread_mutex_unlock ( & var_7 [ var_4 ] ) ; return 0; // Tag.BODY
 }// Tag.OTHER