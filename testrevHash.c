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

static int hashC(char * src) {
int hash = HASH_START_VAL; 
int strLen = strlen(src);
for( int i = strLen -1; i >= 0; i-- ) {
      hash = hash * HASH_PRIME+ src[i];
}
return hash;

}

/*
 * Unit Test for revHash.s
 *
 * long revHash( char * src );
 *
 */
void testrevHash() {

  char * src = "ABCD";
  TEST( revHash(src) == hashC(src) );
  
  src = "";
  TEST( revHash(src) == hashC(src) );

  src = "adlkfn";
  TEST( revHash(src) == hashC(src) );

  src = "aldkfnlaskndf";
  TEST( revHash(src) == hashC(src));
  
  src = "trololol";
  TEST( revHash(src) == hashC(src));

  src = "youregettingtrolled";
  TEST( revHash(src) == hashC(src));

  src = "yeettroll";
  TEST( revHash(src) == hashC(src));

  src = "aklsdnf";
  TEST( revHash(src) == hashC(src));

  src = "adsfasdfasdfasfdasfk";
  TEST( revHash(src) == hashC(src));

}

int main() {
  fprintf( stderr, "Testing revHash...\n\n" );
  testrevHash();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
