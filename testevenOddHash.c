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
 * Unit Test for revHash.s
 *
 * long revHash( char * src );
 *
 */
void testevenOddHash() {

  char * src = "ABCD";
  TEST( evenOddHash(src) == 24002449 );
  
  src = "";
  TEST( evenOddHash(src) == 11 );

  src = "adlkfn";
  TEST( evenOddHash(src) == 797332923  );

  src = "aldkfnlaskndf";
  TEST( evenOddHash(src) == 617772286 );
  
  src = "trololol";
  TEST( evenOddHash(src) == 198791566 );

  src = "youregettingtrolled";
  TEST( evenOddHash(src) == -1027900157 );

  src = "yeettroll";
  TEST( evenOddHash(src) == -1157507401 );

  src = "aklsdnf";
  TEST( evenOddHash(src) == -567099642 );

  src = "adsfasdfasdfasfdasfk";
  TEST( evenOddHash(src) == -1845287348 );

}

int main() {
  fprintf( stderr, "Testing revHash...\n\n" );
  testevenOddHash();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
