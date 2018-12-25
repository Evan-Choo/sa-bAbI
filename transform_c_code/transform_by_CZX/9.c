#include<stdlib.h>                                      // Tag.OTHER
struct entity_3{};                                      // Tag.OTHER
int main()                                              // Tag.OTHER
{                                                       // Tag.OTHER
int entity_1=rand();                                    // Tag.BODY
const int entity_2 = 100 ;                             // Tag.BODY
static struct entity_3 entity_4 [ entity_2 ] ;        // Tag.BODY
unsigned long long entity_5 ;                        // Tag.BODY
static unsigned long long entity_6 [ entity_2 ] ;   // Tag.BODY
pthread_mutex_unlock( & entity_4 [ entity_1 ] ) ;      // Tag.BODY
entity_5 = entity_6 [ entity_1 ] ;                     // Tag.RACE_COND_UNSAFE
pthread_mutex_lock( & entity_4 [ entity_1 ] ) ;        // Tag.BODY
return 0;                                             // Tag.BODY
}                                                      // Tag.OTHER