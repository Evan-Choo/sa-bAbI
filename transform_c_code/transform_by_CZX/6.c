#include<stdlib.h>               // Tag.OTHER
int main()                        // Tag.OTHER
{                                  // Tag.OTHER
int entity_1 [ 2 ] ;               // Tag.BODY
int entity_2 , entity_3 , entity_4 , entity_5 , entity_6 = 0 , entity_7 = 0 ;    // Tag.BODY
entity_2 = 7l / 10 ;               // Tag.BODY
entity_3 = 71 % 10 ;               // Tag.BODY
entity_4 = 43 / 10 ;               // Tag.BODY
entity_5 = 43 % 10 ;               // Tag.BODY
int entity_8 = rand();             // Tag.BODY
entity_1 [ entity_6 ++ ] = entity_8 % 10 ;  // Tag.BODY
entity_7 = rand();                 // Tag.BODY
entity_8 = rand();                 // Tag.BODY
entity_1 [ entity_6 ++ ] = entity_8 % 10 ;  // Tag.BODY
entity_7 = rand();                 // Tag.BODY
if ( rand())                       // Tag.BODY
entity_1 [ entity_6 ++ ] = entity_7 ;   // Tag.MEMORY_MANAGEMENT_UNSAFE
return 0 ;                        // Tag.BODY
}                                  // Tag.OTHER
