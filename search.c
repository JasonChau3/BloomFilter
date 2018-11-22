/*
 * Filename: search.c
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This function will search the three hashtables in the
 * stack and check if the string is located in it.
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>
#include "pa3.h"
#include "pa3Strings.h"
#include <errno.h>
#include <getopt.h>
#include <stdio.h>
/*
   Function Name: search.c
   Function Prototype:int main( int argc, char *argv[]) {
 Description: This function will search the three hashtables in the
 stack and check if the string is located in it.

Parameters: argc - the argument count
argv[] the array of arguments
Side Effects: None
Error Conditions: 
1. Error Calling fopen
2. No input file Specified
3. Extra Arguments for the input flags
*/
int main( int argc, char *argv[]) {
    int opt;
    int incounter = 0;
    FILE *file;
    //loop the opt arg through all the arguments in the flag
    while(( opt = getopt(argc,argv, SEARCH_FLAGS)) != -1){
        switch (opt) {
            //when there is a flag h
            case 'h':
                fprintf(stdout, LONG_SEARCH_USAGE);
                return EXIT_SUCCESS;
                break;


                //when there is a flag i
            case 'i': 
                errno = 0;
                incounter = 1;
                file = fopen(optarg,"rb");
                //if there is error opening the file 
                if ( errno != 0 ) {
                    char buffer[BUFSIZ];//create a string with snprintf
                    snprintf(buffer,BUFSIZ, RTABLE_FILE_ERR);
                    perror(buffer);//print the error message
                        fprintf(stderr, SHORT_SEARCH_USAGE); 
                    return EXIT_FAILURE; 
                } //break out 
                break; 
            //default case
            default:
                fprintf(stderr,MISSING_INFILE);
                fprintf(stderr,SHORT_SEARCH_USAGE);
                return EXIT_FAILURE;
                break;


        }
    }
  //is infile a mandatory file

    //if the mandatory flags arent used print out the errors
    if (incounter == 0) {
        fprintf(stderr, ARG_ERR);
        fprintf(stderr, SHORT_SEARCH_USAGE);
        fclose(file);
        return EXIT_FAILURE;
    }
 
 //if there are more args than normal
    if (optind != argc) {
        fprintf(stderr, EXTRA_ARGS,argv[0]); 
        fprintf(stderr, SHORT_SEARCH_USAGE);
        fclose(file);
        return EXIT_FAILURE;
    }


    //create tables 
    struct Table table;
    struct Table revTable;
    struct Table evoddTable;
    //set there sizes
    
    //call on the readTable
    readTables(file,&table,&revTable,&evoddTable);
    //then call on launchUserQuery
    launchUserQuery(&table,&revTable,&evoddTable);

    //close the file

    //free the memory
    for ( int x = 0; x < evoddTable.size; x++) {
        freeLinkedList(evoddTable.llArray[x]);
    }

    free(table.bitArray);
    free(revTable.bitArray);
    free(evoddTable.llArray);
  //close the file 
   fclose(file);
    return EXIT_SUCCESS;

}
