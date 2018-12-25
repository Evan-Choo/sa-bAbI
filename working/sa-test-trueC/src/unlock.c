#include<stdlib.h> // Tag.OTHER
#include <string.h>// Tag.OTHER
struct var_1 { } ;// Tag.OTHER
struct var_2 { } ;// Tag.OTHER
struct var_3 { } ;// Tag.OTHER
struct var_4 { int var_5 ; } ;// Tag.OTHER
struct var_6 { int var_5 ; } ;// Tag.OTHER
int pthread_mutex_lock(struct pthread_mutex_t* mutex_t){ return 0; } // Tag.OTHER
int pthread_mutex_unlock(struct pthread_mutex_t* mutex_t){ return 0; } // Tag.OTHER
void pthread_cond_wait(struct pthread_cond_t* cond_t, struct pthread_mutex_t* mutex_t); // Tag.OTHER
void pthread_cond_signal(struct pthread_cond_t* cond_t);// Tag.OTHER
int main()// Tag.OTHER
 {// Tag.OTHER
int var_7 = 10 ;// Tag.BODY
int var_8 [10] ;// Tag.BODY
int var_9 [10] ;// Tag.BODY
int var_10 [10] ;// Tag.BODY
const int var_11 = 10 ; // Tag.BODY
struct var_1 var_12 [ var_11 ] ; // Tag.BODY
struct var_4 var_13 [ var_11 ] ; // Tag.BODY
struct var_6 var_14 [ var_11 ] ; // Tag.BODY
struct var_6 var_15 [ var_11 ] ; // Tag.BODY
struct var_3 * var_16 [ var_11 ] ; // Tag.BODY
int var_17 [ var_11 ] ; // Tag.BODY
pthread_mutex_lock ( & var_13 [ var_7 ] ) ; // Tag.BODY
var_17 [ var_7 ] ++ ; // Tag.BODY
pthread_cond_signal ( & var_14 [ var_7 ] ) ; // Tag.COND_SIGNAL_SAFE
pthread_mutex_unlock ( & var_13 [ var_7 ] ) ;return 0; // Tag.BODY
 }// Tag.OTHER