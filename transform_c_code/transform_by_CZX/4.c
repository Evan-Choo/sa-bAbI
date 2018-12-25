#include<stdlib.h>                            // Tag.OTHER
typedef struct entity_1 {                    // Tag.OTHER
    int entity_4;                             // Tag.OTHER
    char *entity_3;                           // Tag.OTHER
} entity_1;                                   // Tag.OTHER
int main()                                   // Tag.OTHER
{                                             // Tag.OTHER
entity_1 * entity_2 = malloc( 16 ) ;          // Tag.BODY
if ( ! rand())return - 1 ;                    // Tag.BODY
entity_2 -> entity_3 = malloc( 8 ) ;           // Tag.MEMORY_MANAGEMENT_SAFE
if ( ! rand()){                                 // Tag.BODY
free( entity_2 ) ;                               // Tag.BODY
return - 1 ;                                     // Tag.BODY
}                                               // Tag.BODY
return 0;                                       // Tag.BODY
}                                               // Tag.OTHER
