/**
   	FileName:     main.c

      
 * * REVISION HISTORY: SoftCom.c
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      	Version     Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Serge Hould      2021-09-15  V1.0        First version of source file
 * 
 * Ezra-Fikru Asfaw 2021-09-21  V1.1        Created and worked on the 
 *                                          first version of soft_com.c 
 *                                          and soft_com.h 
 * 
 * Ezra-Fikru Asfaw 2021-09-28  V1.2        Created and worked on the 
 *                                          second version of soft_com.c. 
 *                                          Most precisely on SM_RETR, 
 *                                          SM_START_BIT, SM_SEND_BIT, 
 *                                          and SM_STOP_BIT
 * 
 * Ezra-Fikru Asfaw 2021-09-28  V1.3        I modified SM_SEND_BIT_ENTRY
 *                                          and SM_SEND_BIT_HANDLER. I also 
 *                                          debug the code to understand the 
 *                                          flow of the code. 
 * 
  * Ezra-Fikru Asfaw 2021-09-28  V1.4       I modified SM_SEND_BIT_ENTRY
 *                                          and SM_SEND_BIT_HANDLER, and 
 *                                          SM_STOP_BIT. I was able to see 
 *                                          the shift and mask on the LATF5.
 *                                          However, I was not able to transmit
 *                                          it from the board to Tera and the 
 *                                          Oscilloscope.   		
 *******************************************************************************
      
 * * REVISION HISTORY: Encoder.c
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      	Version     Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Thommaipillai    21/09/2021  Alpha 1.0   Started coding encoder.c
 * Kaushikmerin                             added case statements for each handler 
 * 
 *Thommaipillai     28/09/2021  Alpha 1.1   Finished state machine case statements
 *Kaushikmerin                              and added code to function with board
 * 		
 * Thommaipillai    05/10/2021  2.0         Encoder task has been debugged and fixed
 * Kaushikmerin                             with LED and idletask() was added to show CPU
 *                                          usage. Next step is to merge.
 *******************************************************************************/
 
#include <xc.h>
#include "Tick_core.h"
#include <stdio.h>
#include "initBoard.h"
#include "encoder.h"
#include "soft_com.h"
#include "console32.h"

    
int main( void){
    
    initIO();
    initLCD();
    initSoftCom();

    while(1){
        
        task1();
        softComTask();
        //delay_us(100);
        idleTask();
        
    }

}// main

