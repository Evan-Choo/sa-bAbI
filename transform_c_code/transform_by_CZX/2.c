#include<stdlib.h>                                       // Tag.OTHER
struct entity_6{};                                       // Tag.OTHER
struct entity_8{};                                       // Tag.OTHER
struct entity_10{};                                      // Tag.OTHER
struct entity_13{};                                      // Tag.OTHER
int main()                                                // Tag.OTHER
{                                                         // Tag.OTHER
int entity_1=rand();                                     // Tag.BODY
void*entity_2;                                           // Tag.BODY
void*entity_3;                                           // Tag.BODY
void*entity_4;                                           // Tag.BODY
const int entity_5 = 100 ;                              // Tag.BODY
static struct entity_6 entity_7 [ entity_5 ] ;         // Tag.BODY
static struct entity_8 entity_9 [ entity_5 ] ;         // Tag.BODY
static struct entity_10 entity_11 [ entity_5 ] ;       // Tag.BODY
static struct entity_10 entity_12 [ entity_5 ] ;       // Tag.BODY
static struct entity_13 * entity_14 [ entity_5 ] ;     // Tag.BODY
static unsigned long long entity_17 [ entity_5 ] ;    // Tag.BODY
pthread_mutex_lock( & entity_9 [ entity_1 ] ) ;          // Tag.BODY
entity_17 [ entity_1 ] ++ ;                              // Tag.BODY
pthread_cond_signal( & entity_11 [ entity_1 ] ) ;        // Tag.COND_SIGNAL_SAFE
pthread_mutex_unlock( & entity_9 [ entity_1 ] ) ;        // Tag.BODY
return 0;                                               // Tag.BODY
}                                                        // Tag.OTHER
