/*
 * Filename: create.c
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This function will populate the hash tables
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>
#include "pa3.h"
#include "pa3Strings.h"
#include <errno.h>
#include <getopt.h>
/*
   Function Name: create.c
   Function Prototype:int main( int argc, char *argv[]) {
Description: This function will free the elements of a linkedlist
Parameters: head a pointer to the head of the linkedlist
Side Effects: None
Error Conditions: none
*/

static struct option getopt_longOpts[]  = {
    {
        LONG_HELP_FLAG,no_argument,0,'h'
    },
    {
        LONG_SIZE_FLAG,required_argument,0,'s'
    },
    {
        LONG_INFILE_FLAG, required_argument,0,'i'
    },
    {
        LONG_OUTPUT_FLAG, required_argument,0,'o'
    }
};
int main( int argc, char *argv[]) {
    int BASE = 10;
    int opt;
    int size;
    char* endptr;
    int incounter = 0;
    int outcounter = 0;
    FILE *file;
    FILE *outFile;
    while(( opt = getopt_long(argc,argv, CREATE_FLAGS , getopt_longOpts, 0)) != -1){
        switch (opt) {
            //when there is a flag h
            case 'h':
                fprintf(stdout, LONG_CREATE_USAGE);
                return EXIT_SUCCESS;
                break;
                //when there is a flag s
            case 's':
                errno = 0;
                size = strtol(optarg, &endptr, BASE);

                //check if size is a valid number or not
                if ( *endptr != '\0') {
                    fprintf(stderr, INVALID_NUM,optarg);
                    fprintf(stderr, SHORT_CREATE_USAGE);
                    return EXIT_FAILURE;
                }

                //check if size is too large a number 
                if ( errno != 0 ) {
                    char buffer[BUFSIZ];
                    snprintf(buffer,BUFSIZ ,TOO_LARGE_NUM, optarg , BASE);
                    perror(buffer);
                    fprintf(stderr, SHORT_CREATE_USAGE);
                    return EXIT_FAILURE;
                }
                //check if size is in range
                if ( rangeCheck (size, MIN_SIZE, MAX_SIZE+1) != 1) {
                    fprintf(stderr, TABLE_SIZE_ERR, MIN_SIZE, MAX_SIZE);
                    fprintf(stderr, SHORT_CREATE_USAGE);
                    return EXIT_FAILURE;
                }
                break;
                //when there is a flag i
            case 'i': 
                errno = 0;
                incounter = 1;
                file = fopen(optarg,"rb");
                //if there is error opening the file 
                if ( errno != 0 ) {
                    char buffer[BUFSIZ];
                    snprintf(buffer,BUFSIZ ,FILTER_ERR);
                    perror(buffer);
                    fprintf(stderr, SHORT_CREATE_USAGE);
                    return EXIT_FAILURE;
                }
                break;

                //when there is a flag o
            case 'o':
                errno = 0;
                outcounter = 1;
                outFile = fopen(optarg, "wb"); //when do you close this file
                //if there is an error opening the file
                if ( errno != 0 ) {
                    char buffer[BUFSIZ];
                    snprintf(buffer,BUFSIZ ,WTABLE_FILE_ERR);
                    perror(buffer);
                    fprintf(stderr, SHORT_CREATE_USAGE);
                    return EXIT_FAILURE;
                }
                break;

        }
    }
    //if the mandatory flags arent used print out the errors
    if (incounter == 0 || outcounter == 0) {
        fprintf(stderr, ARG_ERR);
        fprintf(stderr, SHORT_CREATE_USAGE);
        return EXIT_FAILURE;
    }
    //if there are more args than normal
    if (optind != argc) {
        fprintf(stderr, EXTRA_ARGS,argv[0]); 
        fprintf(stderr, SHORT_CREATE_USAGE);
    }

    if (size == '\0') {
        size = DEFAULT_SIZE;
    }

    //create tables 
    struct Table table;
    struct Table revTable;
    struct Table  evoddTable;
    //set there sizes
    table.size = size;
    revTable.size = size;
    evoddTable.size = size;
    //allocate memory for their arrays
    errno = 0;
    table.bitArray = malloc((sizeof(char)*size));
    //if there is error throw err
    if ( errno != 0 ) {
        perror(MEM_ERR);
        return EXIT_FAILURE;
    }

    errno = 0;
    revTable.bitArray = malloc((sizeof(char)*size));
    //if there is error throw error
    if ( errno != 0 ) {
        free(table.bitArray);
        perror(MEM_ERR);
        return EXIT_FAILURE;
    }
    errno = 0;
    evoddTable.bitArray = malloc((sizeof(linkedList_t)*size));
    //if there is error free and throw error
    if ( errno !=0 ) {
        free(table.bitArray);
        free(revTable.bitArray);
        perror(MEM_ERR);
        return EXIT_FAILURE;
    }
    //set their hashfunctions 
    table.hashFunction = &hash;
    revTable.hashFunction = &revHash;
    evoddTable.hashFunction = &evenOddHash;

    populateTables(&table,&revTable,&evoddTable,file);
    writeTables(outFile,&table,&revTable,&evoddTable);

    //close the file
    fclose(file);
    fclose(outFile);

    //free the memory
    free(table.bitArray);
    free(revTable.bitArray);
    for ( int x = 0; x <size; x++) {
        freeLinkedList(evoddTable.llArray[x]);
    }

    free(evoddTable.llArray);
    return EXIT_SUCCESS;

}
