/*
 * Filename: bitTableAddString
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
  Function Name: bitTableAddString
  Function Prototype:void bitTableAddString( table_t *table, char *string) 
  Description: This function will populate the hash tables
  Parameters: datafile - the list of emails
  htbl - the table for regular hashing
  rtbl - the table for reverse hashing
  eotbl - the table for eveon odd hashing
   Side Effects: None
   Error Conditions: none
   */
void bitTableAddString( table_t *table, char *string) {

  int hash = table->hashFunction( string ) ;
  int index = ((hash % table->size) + table->size) % table->size;
  int bit = 1 << index%8;
  int saved = table->bitArray[index/8] | bit;
  table-> bitArray[index/8] = saved;
}

