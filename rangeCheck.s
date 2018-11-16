/* 
 * Filename: rangeCheck.s
 * Author : Jason Chau
 * ID: cs30fie
 * Description: This is basically a program that takes in three elements: a
 * value, a minimum range, and a maximum range. Then this program first compares
 * if the minimum range is greater than or equal to the maximum range. If it is,
 * it will then throw and error. If it isn't, it will continue on and check if
 * the value is in between the min range and the max range(min is inclusive and
 * max is exclusive) and will tell us if it is in the range or not.
 * Date: 10/11/2018
 * Sources of Help: Piazza
*/

@Raspberry Pi directives
    .cpu           cortex-a53
    .syntax        unified
    .equ           FP_OFFSET,4
labelText:
    .asciz         "The average value is %i\n."
    .global        rangeCheck
    .text
    .align         2  
    /*
  Function Name: rangeCheck.s();
  Function Prototype: rangeCheck(long num, long min, long max); 
  Description: This function will check if the value you passed in
  is in the range of the min and max.
  Parameters: num - the number you use to see if is in range
              min - the minimum value
              max - the maximum value
   Side Effects: None
   Error Conditions: none
   registers used :
    r0 - num
    r1 - min
    r2 - max
    r3 - tempvariable
    */
 
rangeCheck:
    @Standard prologue
    push          {fp,lr}
    add           fp,sp,4       

        cmp           r1,r2
        bge           err1          @Return -1 if small range is bigger than 
        cmp           r0,r1         
        blt           orang         @if value is < min value return 0
        cmp           r0,r2
        bge           orang         @if value is greater than max return 0
        mov           r0,1
        b             end
err1:   
        mov           r0,-1         @return -1 if min range is >= to max range 
        b             end

orang:
        mov           r0,0
        b             end
end:
        mov           r0,r0
    @Standard Epilogue
        sub           sp,fp,FP_OFFSET
        pop           {fp,pc}



