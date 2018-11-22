/*
 * Filename: writeTables
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This function will populate the hash tables
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>
#include "pa3.h"
/*
   Function Name: writeTables
   Function Prototype:void writeTables(FILE *outFile, table_t *htbl,
   table_t *rtbl, table_t *eotbl) 
Description: This function will populate the hash tables
Parameters: datafile - the list of emails
htbl - the table for regular hashing
rtbl - the table for reverse hashing
eotbl - the table for eveon odd hashing
Side Effects: None
Error Conditions: none
*/
void writeTables(FILE *outFile, table_t *htbl, table_t *rtbl, table_t *eotbl) { 
    int countint = 4;
    int numBytes = 8;
    int arr = 7;
    //write in the sizes
    fwrite(&(htbl->size), countint, 1, outFile);
    int size = ((htbl->size + arr) / numBytes);
    //you write it in the file of the bit arrays
    fwrite((htbl->bitArray),1,size, outFile);
    fwrite((rtbl->bitArray),1,size,outFile);

    //loop through the array of the table
    for ( int x = 0 ; x < eotbl->size; x++ ) {
        linkedList_t *ptr = eotbl->llArray[x];
        //loop through all the nodes in each array
        while ( ptr !=  NULL ) {
            //how do i write the array into outfile
            fputs(ptr->value, outFile);
            fputc('\0', outFile);
            //move the pointer to the next node
            ptr = ptr->next;
        }
        fputc('\0', outFile);

    }

}
