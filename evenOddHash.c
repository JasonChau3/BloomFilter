/*
 * Filename: testrevhash
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: Unit test program to test the function revHash().
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"

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
