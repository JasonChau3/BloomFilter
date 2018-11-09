/* File Name : setClock.s
 * Author: Jason Chau
 * Date: 10/26/18
 * ID: cs30fie
 * Description: This program is meant to set the given time into a time pattern
 *and put it into something called clock. Which then is the format of how the
 *time is supposed to read as.
 *Source of Help: PIAZZA
 */
@Raspberry Pi Directive
        .cpu        cortex-a53
        .syntax     unified
        .global     setClock
        .text
        .align     2


        .equ        FP_OFFSET,4
        .equ        SP_OFFSET,24
        .equ        HOUR,-8
        .equ        CLOCK,-12
        .equ        TIMEINFO,-16
        .equ        MIN,-20
        .equ        SEC,-24
        .equ        AM, -28
        .equ        TEN, 10
        .equ        BYTE, 4
        .equ        THREE,3
        .equ        TWO,2
        .equ        ONE,1

/*
  Function Name: setClock.s()
  Function Prototype: setClock( unsigned long * clock, const struct timeInfo*
  time info)
  Description: This function will set the time pattern in the clock using the
  hours , seconds, minutes in the struct timeInfo.
  Parameters: clock which is the time to convert.
              time info- the struct with all the data in it
   Side Effects: None
   Error Conditions: none
   registers used :
    r0 - clock
    r1 - timeInfo
    r2 - tempvariable
    r3 - tempvariable
    */
  
setClock:
        push    {fp,lr}
        add     fp,sp, FP_OFFSET
        sub     sp,sp,SP_OFFSET

        str     r0, [fp,CLOCK]
        str     r1, [fp,TIMEINFO]

        @GET THE HOUR
        ldr     r0, =timeInfo_hourOffset        @load in the OFFSETofHOUR
        ldr     r0, [r0]
        ldr     r1, [fp, TIMEINFO]              @get the actual value ofit
        ldr     r0, [r1,r0]                     @r0 is the HOUR
        str     r0, [fp,HOUR]                   @store hour to HOUR

        mov     r1,TEN
        bl      getRemainder                    @r0 is the second digit of hour

        ldr     r1, [fp,HOUR]                   @r1 is the Hour
        mov     r2,TEN
        sdiv    r1,r1,r2                        @r1 = min/10
        mov     r2, BYTE                        @shift r1 left four
        lsl     r1,r1,r2                        @r1 is first digit of HOUR

        orr     r0,r1,r0                        @add first and second digits
        ldr     r1, [fp,CLOCK]                  @get the value and put into
        mov     r3, THREE                       @clock
        strb    r0, [r1,r3]                     @store the min to the clock

        


        @GET THE MINS
        ldr     r0, =timeInfo_minOffset         @load in the minute
        ldr     r0, [r0]
        ldr     r1, [fp, TIMEINFO]              
        ldr     r0, [r1,r0]                     @r0 is the minute
        str     r0, [fp,MIN]                    @store min to MIN

        mov     r1,TEN
        bl      getRemainder                    @r0 is the second digit of mins

        ldr     r1, [fp,MIN]      
        mov     r2,TEN
        sdiv    r1,r1,r2                        @r1 = min/10
        mov     r2, BYTE
        lsl     r1,r1,r2                        @r1 is first digit of mins

        orr     r0,r1,r0
        ldr     r1, [fp,CLOCK]          
        mov     r3, TWO
        strb    r0, [r1,r3]                     @store the min to the clock

        
        @GET THE SECS
        ldr     r0, =timeInfo_secOffset         @load in the minute
        ldr     r0, [r0]
        ldr     r1, [fp, TIMEINFO]              
        ldr     r0, [r1,r0]                     @r0 is the minute
        str     r0, [fp,SEC]                    @store min to MIN

        mov     r1,TEN
        bl      getRemainder                    @r0 is the second digit of mins

        ldr     r1, [fp,SEC]      
        mov     r2,TEN
        sdiv    r1,r1,r2                        @r1 = min/10
        mov     r2, BYTE
        lsl     r1,r1,r2                        @r1 is first digit of mins

        orr     r0,r1,r0
        ldr     r1, [fp,CLOCK]          
        mov     r3, ONE
        strb    r0, [r1,r3]                     @store the min to the clock

        @GET THE AM/PM
        ldr     r0, =timeInfo_ampmOffset        @get am/pm offset
        ldr     r0, [r0]
        ldr     r1, [fp, TIMEINFO]              @get the value of am/pm
        ldr     r0, [r1,r0]                     @r0 is am/pm

        ldr     r1, [fp,CLOCK]                  @r1 is the long
        strb    r0, [r1]                        @store the am/pm in the long


        @Standard Epilogue
        sub     sp, fp, FP_OFFSET
        pop     {fp, pc}

        
        

