/*
 * Filename: prependNode
 * Author: Jason Chau
 * Userid: cs30fie
 * Description: This program is meant to add a node into a 
 * linked list
 * Date: 11/7/18
 * Sources of Help: PIAZZA
 */

#include <string.h>
#include <stdlib.h>

#include "pa3.h"
/*
   Function Name: prependNode()
   Function Prototype: void prependNode (linkedList_t ** head, char * str) {
Description: This function will add a node to the node
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
    char *string = malloc(sizeof(char)*(strlen(str)+1)); //allocate memory for the string
    //+1 because of the null terminator
    if (string == NULL) {
        free(linked);
        perror(MEM_ERR);
        return;
    }
    //how do you allocate the memory with the string?
    strcpy(string, str);
    linked->value = string;
    linked->next =(*head); //dereference head once or twice?
    *head = linked; //make the head point to the linked 

}
