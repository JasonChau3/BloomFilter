/*
 * Filename: launchUserQueryEC.c
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
    char std[BUFSIZ];
    int count = 0;
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
        } //loop through the whole string
        for ( int x = 0; x < strlen(string)+1; x++) {
            //put the string into the string
            std[count] = string[x];
            //add it all to the table
            //if what you added is a space or a null terminator
            if ( std[count] == '\0' || std[count] == ' ') {
                if ( std[count-1] != ' '){
                std[count] = '\0';
                int numString = checkTables(std,htbl,rtbl,eotbl);
                count = 0;

                if (numString == EXACT_MATCH) {  //if all of them match
                    fprintf(stdout,FOUND_IN_ALL, std);
                }
                else if ( numString > 0 ) { //if some of them match
                    fprintf(stdout, FOUND_IN_SOME,std,numString);
                }
                else if ( numString == 0) { //if none of them match
                    fprintf(stdout,WORD_NOT_FOUND,std);
                }
            }
            }
            else{
            count++;
            }
        }


        fprintf(stdout,USER_PROMPT);
    }
        fprintf(stdout,"%c", '\n');
}
