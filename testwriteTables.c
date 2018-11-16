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
 * Unit Test for writeTables
 *
 * long hash( char * src );
 *
 */
void testwriteTables() {

    //allocate the memory for the hash table
    table_t table = {
        .size = DEFAULT_SIZE,
        .bitArray = calloc(sizeof(char), (DEFAULT_SIZE +7 )/8),
        .hashFunction = hash
    };

    //allocate the memory for the revhash table
    table_t revTable = {
        .size = DEFAULT_SIZE,
        .bitArray = calloc(sizeof(char), (DEFAULT_SIZE +7 )/8),
        .hashFunction = revHash
    };
    //allocate the memory for the evenoddHashtable
    table_t evoddTable = {
        .size = DEFAULT_SIZE,
        .llArray = calloc (sizeof(linkedList_t*), DEFAULT_SIZE),
        .hashFunction = evenOddHash
    };

    //open the file
    FILE *inputFile = fopen("testFile", "rb");
    //populate the tables
    populateTables(&table,&revTable,&evoddTable,inputFile);
    //close the file
    fclose(inputFile);

    //write in the output of the file
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
