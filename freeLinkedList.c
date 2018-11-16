/*
 * Filename: freeLinkedList
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This function will free all the memory of the linkedlist.
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "pa3.h"
/*
  Function Name: freeLinkedList()
  Function Prototype:void freeLinkedList(linkedlist_t *head) {
  Description: This function will free the elements of a linkedlist
  Parameters: head a pointer to the head of the linkedlist
   Side Effects: None
   Error Conditions: none
   */
void freeLinkedList(linkedList_t *head) {
    //loop through the whole linkedlist
    while ( head != NULL) {
    //get the actual node from the pointer
    linkedList_t *pointer = head->next;
    //iterate the head
    free(head->value);
    //free the value
    free(head);
    //free the pointer next
    head = pointer;
    }
  }
