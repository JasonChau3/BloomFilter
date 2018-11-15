/*
 * Filename: evenOddHash
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This program is meant to set a word into a database
 called a hash.
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "pa3.h"
/*
  Function Name: evenOddhash()
  Function Prototype: int evenOddHash(char * str);
  Description: This function will set the string into a hash value.
  Parameters: *str - a string pointer that points to a string
   Side Effects: None
   Error Conditions: none
   */
 
int evenOddHash(char * str) {
    int INCR = 2;
    int hash = HASH_START_VAL;
    int strLen = strlen(str); //get the start values and the strlen
    for( int i = 0; i < strLen; i+=INCR ) { //loop through and do all the even
          hash = hash * HASH_PRIME + str[i];
    } //loop through and do all the odd values.
    for( int i = 1; i < strLen; i+=INCR ) {
          hash = hash * HASH_PRIME + str[i];
    }
    return hash;

}
