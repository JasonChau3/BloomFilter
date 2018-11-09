/*
 * Filename: testhash
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: Unit test program to test the function hash().
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"

static int hashC(char * src) {
int hash = HASH_START_VAL; 
int strLen = strlen(src);
for( int i = 0; i < strLen; i++ ) {
      hash = hash * HASH_PRIME+ src[i];
}
return hash;

}

/*
 * Unit Test for hash.s
 *
 * long hash( char * src );
 *
 */
void testhash() {

  char * src = "ABCD";
  /* Validate the hash value. */
  TEST( hash(src) == hashC(src) );
  
  src = "";
  TEST( hash(src) == hashC(src) );

  src = "adlkfn";
  TEST( hash(src) == hashC(src) );

  src = "aldkfnlaskndf";
  TEST( hash(src) == hashC(src));
 
 src = "trololol";
  TEST( hash(src) == hashC(src));

  src = "youregettingtrolled";
  TEST( hash(src) == hashC(src));

  src = "yeettroll";
  TEST( hash(src) == hashC(src));

  src = "aklsdnf";
  TEST( hash(src) == hashC(src));

  src = "adsfasdfasdfasfdasfk";
  TEST( hash(src) == hashC(src));
  

}

int main() {
  fprintf( stderr, "Testing hash...\n\n" );
  testhash();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
