/*
 * Filename: prependNode
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This program is meant to set a word into a database
 called a hash.
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "pa3.h"
/*
  Function Name: prependNode()
  Function Prototype: void prependNode (linkedList_t ** head, char * str) {
  Description: This function will set the string into a hash value.
  Parameters: *str - a string pointer that points to a string
    head - pointer to the pointer to the head of the list
   Side Effects: None
   Error Conditions: none
   */
void prependNode (linkedList_t ** head, char * str) {

    linkedList_t *linked = malloc(sizeof(linkedList_t));
    if (linked == NULL) {
    perror(MEM_ERR);
    return;
    }
//is it 4 times stringlength?
    char *string = malloc(strlen(str));
    if (string == NULL) {
        free(linked);
        perror(MEM_ERR);
        return;
    }
    //how do you allocate the memory with the string?
    strcpy(string, str);
    linked->value = string;
    linked->next =(*head);
    *head = linked; //make the head point to the linked 
 

  //do head.next = the node you made
  // and then the node you made next node is the saved value.
  
  }
