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
#include <stdio.h>
#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"

/*
 * Unit Test for hash.s
 *
 * long hash( char * src );
 *
 */
void testwriteTables() {
table_t table;
table_t revTable;
table_t evoddTable;

table.size = BUFSIZ;
revTable.size = BUFSIZ;
evoddTable.size = BUFSIZ;

table.hashFunction = &hash;
revTable.hashFunction = &revHash;
evoddTable.hashFunction = &evenOddHash;

FILE *inputFile = fopen("file1", "rb");
populateTables(&table,&revTable,&evoddTable,inputFile);
fclose(inputFile);

FILE *outputFile = fopen("file2", "wb");
writeTables(outputFile,&table,&revTable,&evoddTable);
fclose(outputFile);


}

int main() {
  fprintf( stderr, "Testing hash...\n\n" );
  testwriteTables();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
