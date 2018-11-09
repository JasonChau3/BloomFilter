/* File Name : revHash.s
 * Author: Jason Chau
 * Date: 10/26/18
 * ID: cs30fie
 * Description:This program is meant to set a word into a database
 * called a hash.
Source of Help: PIAZZA
 */
@Raspberry Pi Directive
        .cpu        cortex-a53
        .syntax     unified
        .global     revHash
        .text
        .align     2


        .equ        FP_OFFSET,4
        .equ        SP_OFFSET,16
        .equ        POINTERSTR, -8
        .equ        STRLEN,-12
        .equ        HASHVALUE,-16
/*
  Function Name: revhash()
  Function Prototype: int revhash(char * str);
  Description: This function will set the string into a hash value.
  Parameters: *str - a string pointer that points to a string
   Side Effects: None
   Error Conditions: none
   registers used :
    r0 - str
    r1 - hash
    r2 - counter/hashprime
    r3 - end loop
    */
  
revHash:
        push    {fp,lr}
        add     fp,sp, FP_OFFSET
        sub     sp,sp,SP_OFFSET
        
        str     r0, [fp, POINTERSTR]
        bl      strlen 
        sub     r0, r0, 1                         @strlength -1
        str     r0, [fp, STRLEN]
        mov     r2, r0                            @get the strlength to r2
        ldr     r1, =HashStartVal                 @load in the address of
        ldr     r1, [r1]                          @hashStartVal and get the val
        ldr     r0, [fp,POINTERSTR]
        mov     r3,0                              @end loop
        
        @beginning of the loop
        cmp     r2, r3                            @if counter < 0
        blt     endLoop                           @end the loop

Loop:
        ldr     r2, =HashPrime  
        ldr     r2, [r2]
        ldr     r0, [fp, POINTERSTR]              @r0 is the *str
        mul     r1, r1, r2                        @multiply hash with hashprime
        ldr     r2, [fp, STRLEN]                  @load in the counter
        ldrb    r0, [r0, r2]                      @str[i]
        add     r1, r1, r0                        @hash = hash +str[i]
        str     r1, [fp, HASHVALUE]               @store the hashvalue
        sub     r2,r2,1                           @counter--
        str     r2, [fp,STRLEN]
        cmp     r2,r3               
        blt     endLoop                           @if counter >= strlen go end
        b       Loop                              @otherwise keep looping


endLoop:
       mov      r0,r1                             @return hash.

        
        @Standard Epilogue
        sub     sp, fp, FP_OFFSET
        pop     {fp, pc}

        
        

