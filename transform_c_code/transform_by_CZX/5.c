#include<stdlib.h>                                 // Tag.OTHER
int main()                                         // Tag.OTHER
{                                                  // Tag.OTHER
int entity_1=rand();                              // Tag.BODY
char  entity_2[10];                               // Tag.BODY
const int entity_3 = 128 ;                       // Tag.BODY
char entity_4 [ 25 ] ,                      // Tag.BODY
entity_5 [ ] = "result.txt" ,             // Tag.BODY
entity_6 [ entity_3 ] , * entity_7 ,       // Tag.BODY
entity_8 [ 100 ] [ 40 ] = { { '0' } } ;          // Tag.BODY
const char entity_9 [ ] = " .,;:!-\n\t" ;      // Tag.BODY
int entity_10 [ 100 ] = { 0 } ,                 // Tag.BODY
 entity_11 , entity_12 = 0 , entity_13 = 0 ,   // Tag.BODY
 entity_14 = 0 , entity_15 = 0 ; // Tag.BODY
if ( rand()){                                    // Tag.BODY
strcpy(entity_4, entity_2[1]);                   // Tag.STRCPY_UNSAFE
} else {                                        // Tag.BODY
                                                // Tag.BODY
                                                // Tag.BODY
}                                               // Tag.BODY
return 0 ;                                     // Tag.BODY
}                                               // Tag.OTHER
