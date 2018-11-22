/*
 * Filename: launchUserQuery.c
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This function will check what the user wants to see is 
 * spamm
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pa3.h"
#include "pa3Strings.h"
/*
   Function Name: launchUserQuery
   Function Prototype:void launchUserQuery(table_t *htbl, table_t *rtbl,
   table_t *eotb)
Description: This function will check what the user wants to see is 
spamm
Parameters: datafile - the list of emails
htbl - the table for regular hashing
rtbl - the table for reverse hashing
eotbl - the table for eveon odd hashing
Side Effects: None
Error Conditions: if fails to allocate memory
*/
void launchUserQuery(table_t *htbl, table_t *rtbl,
        table_t *eotbl) {

    fprintf(stdout,USER_PROMPT);

    char string[BUFSIZ];
    //how to loop

    while (fgets(string,BUFSIZ,stdin )) {
        //    fprintf(stdout,"%s\n", string); 
        char *change = strchr(string, '\n');
        if ( change != NULL ) {
            *change = '\0'; 
        }
        if ( string[0] == '\0' ) {
            fprintf(stdout,USER_PROMPT);
            continue;   //check if the first input is enter
        }
        char *ptr = string;

        while (*ptr != '\0') { //loop through the whole string
            char c = tolower(*ptr);        //make that value to lower case
            *ptr = c;
            ptr = ptr + 1;         //increment the pointer
        }
        //add it all to the table
        int numString = checkTables(string,htbl,rtbl,eotbl);

        if (numString == EXACT_MATCH) {  //if all of them match
            fprintf(stdout,FOUND_IN_ALL, string);
        }
        else if ( numString > 0 ) { //if some of them match
            fprintf(stdout, FOUND_IN_SOME,string,numString);
        }
        else if ( numString == 0) { //if none of them match
            fprintf(stdout,WORD_NOT_FOUND,string);
        }

        fprintf(stdout,USER_PROMPT);
    }
    fprintf(stdout,"%c", '\n');
}
