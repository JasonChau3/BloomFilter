/*
 * Filename: checkTables
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This function will check if the tables contain a certain string
 * or not 
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "pa3.h"
/*
   Function Name: checkTables()
   Function Prototype:int checkTables(char *str, table_t *htbl, table_t *rtbl,
   table_t *eotbl)

Description: This function will check if the tables contain a certain string
or not 
Parameters: str - the string to be searched 
htbl - the table for regular hashing
rtbl - the table for reverse hashing
eotbl - the table for eveon odd hashing
Side Effects: None
Error Conditions: none
*/
int checkTables(char *str, table_t *htbl, table_t *rtbl, table_t *eotbl) {
    int numFound = 0;
    int EXACT = 4;

    if ( retrieveBit(htbl,str) == 1) { //if retrieveBit found the string
        numFound++; //increment the counter


        if ( retrieveBit(rtbl,str) == 1) { //if retrieveBit found the string
            numFound++; //increment the counter

             //see if it is in the linked list
            linkedList_t *ptr = retrieveLinkedList(eotbl,str);
            if ( ptr != NULL ) {
                numFound++;  

                while ( ptr != NULL ) {

                    if (strcmp(ptr->value,str) == 0 ) { //check if the string 
                        //is the same string as the provided in the linked list
                        numFound++;
                    }
                    ptr = ptr ->next;
                }
            }
        }
    }
//if it is exact amount return the exact
    if ( numFound == EXACT) {
        return EXACT_MATCH;
    }

    return numFound;
}
