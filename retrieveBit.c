/*
 * Filename: retrieveBit
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
  Function Name: retrieveBit
  Function Prototype:int retrieveBit( table_t *table, char *string) {
  Description: This function will get the bit of the string
  Parameters: 
  table - the table to be searched in
  string - the string that we will find
   Side Effects: None
   Error Conditions: none
   */
int retrieveBit( table_t *table, char *string) {
  int bitnum = 8;
  //make the hashfunction
  int hash = table->hashFunction( string ) ;
  //get the index
  int index = ((hash % table->size) + table->size) % table->size;
  //shift the bit by index % bitnum
  int bit = 1 << (index%bitnum);
  //get that savedbit
  int saved = table->bitArray[index/bitnum] & bit;
  //and set it
  return saved >> (index%bitnum);
}

