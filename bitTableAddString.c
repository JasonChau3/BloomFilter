/*
 * Filename: bitTableAddString
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This function will populate the table in a certaian index
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "pa3.h"
/*
  Function Name: bitTableAddString
  Function Prototype:void bitTableAddString( table_t *table, char *string) 
  Description: This function will populate the hash tables in a index
  Parameters: datafile - the list of emails
  htbl - the table for regular hashing
  rtbl - the table for reverse hashing
  eotbl - the table for eveon odd hashing
   Side Effects: None
   Error Conditions: none
   */
void bitTableAddString( table_t *table, char *string) {
  int bitnum = 8;
  //make the hashfunction
  int hash = table->hashFunction( string ) ;
  //get the index
  int index = ((hash % table->size) + table->size) % table->size;
  //shift the bit by index % bitnum
  int bit = 1 << (index%bitnum);
  //get that savedbit
  int saved = table->bitArray[index/bitnum] | bit;
  //and set it
  table-> bitArray[index/bitnum] = saved;
}

