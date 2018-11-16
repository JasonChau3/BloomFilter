/*
 * Filename: testprependNode
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: Unit test program to test the function prependNode()
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
 *
 */

void testprependNode() {
//set up for the tester
linkedList_t head;
linkedList_t second;
linkedList_t *headptr = &head;
linkedList_t **dbheadptr = &headptr;

//make the string
char *string = "ABC";
head.next = &second;
head.value = "first";
second.value= "second";
//prepend twice
prependNode(dbheadptr, string);

string = "B";
//loop through all of it to see if they are the right values
prependNode(dbheadptr, string);
TEST(strcmp(headptr->value, "B")==0);
headptr = headptr->next;
TEST(strcmp(headptr->value,"ABC") == 0);
headptr = headptr->next;
TEST(strcmp(headptr->value,"first") == 0);
headptr = headptr->next;
TEST(strcmp(headptr->value,"second") == 0);

//check edge case where head doesn't point to anything
linkedList_t head2;
linkedList_t *head2ptr = &head2;
linkedList_t **dbhead2ptr = &head2ptr;
prependNode(dbhead2ptr,string);
TEST(strcmp(head2ptr->value, "B")== 0);

}

int main() {
  fprintf( stderr, "Testing hash...\n\n" );
  testprependNode();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
