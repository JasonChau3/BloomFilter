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
/*
  Function Name: create.c
  Function Prototype:int main( int argc, char *argv[]) {
  Description: This function will free the elements of a linkedlist
  Parameters: head a pointer to the head of the linkedlist
   Side Effects: None
   Error Conditions: none
   */

static struct option getopt_longOpts[] {
 {
    "size",optional-argument,'s',0
 },
 {
    "help",optional-argument,'h', 0
 },
 {
    "infile", argument-required,'i',0
 },
 {
     "output", argument-required,'o',0
 }
}
int main( int argc, char *argv[]) {
int x = getopt_long(argc,argv
 }
