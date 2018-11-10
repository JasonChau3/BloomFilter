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
  char * srd = "acbd";
  char * src = "ABCD";
  TEST( evenOddHash(src) == 24002449 );
  
  src = "abcd";
  TEST( evenOddHash(src) == hash(srd));
  
  src = "ghki";
  srd = "gkhi";
  TEST( evenOddHash(src) == hash(srd));

  src = "asdfgh";
  srd = "adgsfh";
  TEST( evenOddHash(src) == hash(srd));

  src = "";
  TEST( evenOddHash(src) == 11 );

  src = "adlkfn";
  srd = "alfdkn";
  TEST( evenOddHash(src) == hash(srd));
  

  src = "aldkfnlaskndf";
  srd = "adflsnflknakd";
  TEST( evenOddHash(src) == hash(srd));
  
  src = "trololol";
  srd = "tooorlll";
  TEST( evenOddHash(src) == hash(srd));

  src = "hotdog";
  srd = "htoodg";
  TEST( evenOddHash(src) == hash(srd));

  src = "donkey";
  srd = "dneoky";
  TEST( evenOddHash(src) == hash(srd));
}

int main() {
  fprintf( stderr, "Testing revHash...\n\n" );
  testevenOddHash();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
