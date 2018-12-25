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
char var_5 [10] ;// Tag.BODY
const int var_6 = 10 ; // Tag.BODY
char var_7 [ 25 ] , var_8 [ ] = "result.txt" , // Tag.BODY
 var_9 [ var_6 ] , // Tag.BODY
 * var_10 , // Tag.BODY
var_11 [ 100 ] [ 40 ] = { { '0' } } ; // Tag.BODY
const char var_12 [ ] = " .,;:!-\n\t" ; // Tag.BODY
int var_13 [ 100 ] = { 0 } , var_2 , // Tag.BODY
var_14 = 0 , // Tag.BODY
var_15 = 0 , // Tag.BODY
var_16 = 0 , // Tag.BODY
var_17 = 0 ; // Tag.BODY
if ( var_4 > 1 ) { // Tag.BODY
strcpy ( var_7 , var_5 [ 1 ] ) ; // Tag.STRCPY_UNSAFE
} else { // Tag.BODY
} return 0; // Tag.BODY
 }// Tag.OTHER