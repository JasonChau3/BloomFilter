/*
 * Filename: testhash
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: Unit test program to test the function hash().
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa3.h"



/*
 * Unit Test for prependNode()
 *
 * long hash( char * src );
 *
 */
void testprependNode() {
linkedList_t head;
linkedList_t second;
linkedList_t *headptr = &head;
linkedList_t **dbheadptr = &headptr;

char *string = "ABC";
head.next = &second;
head.value = "first";
second.value= "second";

prependNode(dbheadptr, string);

string = "B";
prependNode(dbheadptr, string);
oTEST(strcmp(headptr->value, "B")==0);
headptr = headptr->next;
TEST(strcmp(headptr->value,"ABC") == 0);
headptr = headptr->next;
TEST(strcmp(headptr->value,"first") == 0);
headptr = headptr->next;
TEST(strcmp(headptr->value,"second") == 0);


}

int main() {
  fprintf( stderr, "Testing hash...\n\n" );
  testprependNode();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
