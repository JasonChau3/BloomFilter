 /* File Name : retrieveLinkedList.s
 * Author: Jason Chau
 * Date: 10/26/18
 * ID: cs30fie
 * Description: This program is meant to get the word at the 
 *linkedlist 
 *Source of Help: PIAZZA
 */
@Raspberry Pi Directive
        .cpu        cortex-a53
        .syntax     unified
        .global     retrieveLinkedList
        .text
        .align     2


        .equ        FP_OFFSET,4
        .equ        SP_OFFSET,24
        .equ        TABLE, -8
        .equ        STRING, -12
        .equ        HASH, -16
        .equ        SIZE, -20
        .equ        INDEX, -24
        .equ        BYTE, 4
/*
  Function Name: retrieveLinkedList
  Function Prototype: void retrieveLinkedList( table_t *table, char *string)
  Description: This function will check if the string is in the llarray
  Parameters: *str - a string pointer that points to a string
              *table - the table to be checked
   Side Effects: None
   Error Conditions: none
   registers used :
    r0 - table_t *table
    r1 - char *string
    r2 - temp variable
    r3 - temp variable
    */
  
retrieveLinkedList:
        push    {fp,lr} 
        add     fp,sp, FP_OFFSET
        sub     sp,sp,SP_OFFSET
        
        str     r0, [fp, TABLE]
        str     r1, [fp, STRING]
        ldr     r3, =HashFunctionOffset
        ldr     r3, [r3]
        ldr     r2, [r0, r3]                    @load in the the hashfunction
        mov     r0, r1                          @move the string to r0
        blx      r2                             @call the hsah function
        str     r0, [fp, HASH]                  @store the hash value

        ldr     r0, [fp, TABLE]                 @load in all the values
        ldr     r1, [fp, STRING]
        ldr     r2, [fp, HASH]
        ldr     r3, =SizeOffset
        ldr     r3, [r3]
        ldr     r0, [r0, r3]                    @get the size 
        str     r0, [fp, SIZE]                  @store in the size
        
        mov     r1, r0                          @r1 is size
        mov     r0, r2                          @r2 is the hash
        bl      getRemainder                    

        ldr     r1, [fp, SIZE]
        add     r0, r0, r1                      @r0 = (hash % size) + size
        bl      getRemainder                    @ r0 % size
                                                @multiply r0 with 4
        mov     r3, BYTE                        @index *4
        mul     r0, r0, r3                       

        @r0 is now index
        str     r0, [fp, INDEX]
        ldr     r3, =ArrayOffset                @get the array offset
        ldr     r3, [r3]
        ldr     r0, [fp, TABLE]                 @load in r0 as the table
        ldr     r0, [r0, r3]                    @add the arrayoffset to the tab
        
        ldr     r1, [fp, INDEX]                 @get the array index
        add     r0, r0,r1                       @r0 is llArray[index]
        ldr     r0, [r0]                        @load in the actual value 

       @Standard Epilogue
        sub     sp, fp, FP_OFFSET
        pop     {fp, pc}

        
        

