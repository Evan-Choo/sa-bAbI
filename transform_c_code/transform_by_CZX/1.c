#include<stdlib.h>                                                             // Tag.OTHER
struct entity_4{};                                                             // Tag.OTHER
struct entity_6{};                                                             // Tag.OTHER
int main()                                                                     // Tag.OTHER
{                                                                              // Tag.OTHER
int entity_1=rand();                                                           // Tag.BODY
const int entity_2 = 100 ;                                                    // Tag.BODY
static unsigned long long entity_3 [ entity_2 ] ;                           // Tag.BODY
static struct entity_4 entity_5 [ entity_2 ] ;                               // Tag.BODY
static struct entity_6 entity_7 [ entity_2 ] ;                               // Tag.BODY
unsigned long long entity_8 ;                                                // Tag.BODY
pthread_mutex_lock( & entity_5 [ entity_1 ] ) ;                                // Tag.BODY
entity_8 = rand();                                                             // Tag.BODY
if ( rand()){                                                                 // Tag.BODY
pthread_cond_wait( & entity_7 [ entity_1 ] , & entity_5 [ entity_1 ] ) ;      // Tag.COND_WAIT_UNSAFE
entity_8 = rand();                                                            // Tag.BODY
}                                                                             // Tag.BODY
pthread_mutex_unlock( & entity_5 [ entity_1 ] ) ;                             // Tag.BODY
return 0;                                                                    // Tag.BODY
}                                                                            // Tag.OTHER
