/*
 * Filename: testpopulateTables
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: Unit test program to test the function populate tables
 * Date: 11/16/18
 * Sources of Help: PIAZZA, TUTOR ALAN
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"

/*
 * Unit Test for populateTables
 *
 *
 */
void testpopulateTables() {

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

    for ( int x = 0; x < DEFAULT_SIZE; x++ ) {
        if (evoddTable.llArray[x] != NULL ){
            linkedList_t *dog = evoddTable.llArray[x];

            while ( dog != NULL) {

                fprintf(stdout, "%s\n", dog->value);
                dog = dog->next;
            }

        }
    }
}
int main() {
    fprintf( stdout, "Testing hash...\n\n" );
    testpopulateTables();
    fprintf( stdout, "\nDone running tests.\n" );
    return 0;
}
