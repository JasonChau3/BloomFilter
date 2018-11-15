/*
 * Filename: populateTable
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
  Function Name: populateTable()
  Function Prototype:void populateTable(table_t *htbl, table_t *rtbl,
 table_t *eotbl,FILE *datafile) 
  Description: This function will populate the hash tables
  Parameters: datafile - the list of emails
  htbl - the table for regular hashing
  rtbl - the table for reverse hashing
  eotbl - the table for eveon odd hashing
   Side Effects: None
   Error Conditions: none
   */
 void populateTables(table_t *htbl, table_t *rtbl,
 table_t *eotbl,FILE *datafile) {

     char string[BUFSIZ];
     //how to loop
     
     while (fgets(string,BUFSIZ, datafile) != NULL ) {
     char *change = strchr(string, '\n');
     *change = '\0'; 
     char *ptr = string;

     while (ptr != '\0') { //loop through the whole string
     tolower(*ptr);        //make that value to lower case
     ptr = ptr + 1;         //increment the pointer
     }

     bitTableAddString(htbl, string);
     bitTableAddString(rtbl, string);
     llTableAddString(eotbl, string);
  }
  }
