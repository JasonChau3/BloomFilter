/*
 * Filename: testevenOddHash    
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: Unit test program to test the function testevenOddHash().
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"



/*
 * Unit Test for revhashC.s
 *
 * long revhashC( char * src );
 *
 */

static int hashC(char * src) {
int hash = HASH_START_VAL; 
int strLen = strlen(src);
for( int i = 0; i < strLen; i++ ) {
      hash = hash * HASH_PRIME + src[i];
}
return hash;

}

void testevenOddHash() {
  char * srd = "acbd";
  char * src = "ABCD";
  TEST( evenOddHash(src) == 24002449 );
  
  src = "abcd";
  TEST( evenOddHash(src) == hashC(srd));
  
  src = "ghki";
  srd = "gkhi";
  TEST( evenOddHash(src) == hashC(srd));

  src = "asdfgh";
  srd = "adgsfh";
  TEST( evenOddHash(src) == hashC(srd));

  src = "";
  TEST( evenOddHash(src) == 11 );

  src = "adlkfn";
  srd = "alfdkn";
  TEST( evenOddHash(src) == hashC(srd));
  

  src = "aldkfnlaskndf";
  srd = "adflsnflknakd";
  TEST( evenOddHash(src) == hashC(srd));
  
  src = "trololol";
  srd = "tooorlll";
  TEST( evenOddHash(src) == hashC(srd));

  src = "hotdog";
  srd = "htoodg";
  TEST( evenOddHash(src) == hashC(srd));

  src = "donkey";
  srd = "dneoky";
  TEST( evenOddHash(src) == hashC(srd));
}

int main() {
  fprintf( stderr, "Testing revhashC...\n\n" );
  testevenOddHash();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
