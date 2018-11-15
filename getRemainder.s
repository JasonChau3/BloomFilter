/* 
 * Filename: getRemainder.s
 * Author : Jason Chau
 * ID: cs30fie
 * Description: This file is basically a program takes a divisor and dividend
 * and gives you the remainder when you divide the numbers. However this program
 * will not work if the divisor is zero.
 * Date: 10/11/2018
 * Sources of Help: Piazza
*/

@Raspberry Pi directives
    .cpu           cortex-a53
    .syntax        unified
    .equ           FP_OFFSET,4
labelText:
    .asciz         "The remainder is %i\n."
    .global        getRemainder 
    .text
    .align         2 
    /*
  Function Name getRemainder.s()
  Function Prototype: convertTime(( long dividend, long divisor)
  Description: This function will get the remainder of the dividend
  and divisor values you put in
  Parameters: dividend the value you want to be used to be divided by
  divisor: the value you want to use to divide
   Side Effects: None
   Error Conditions: none
   registers used :
    r0 - dividend
    r1 - divisor
    r2 - tempvariable
    r3 - tempvariable
    */
 
getRemainder:
    @Standard prologue
    push          {fp,lr}
    add           fp,sp,4     
        
        sdiv          r2, r0, r1        @divide it and get the value 
        mul           r3, r2, r1        @multiply that value with the divisor
        sub           r0, r0, r3        @then subtract the dividend with that
                                        @multiplied value to get the remainder


    @Standard Epilogue
        sub           sp,fp,FP_OFFSET
        pop           {fp,pc}



