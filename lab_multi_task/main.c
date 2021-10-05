/**
   	FileName:     main.c
	
 
	Description: 
      
 * * REVISION HISTORY:
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      	Version     Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Thommaipillai    21/09/2021  Alpha 1.0   Started coding encoder.c
 * Kaushikmerin                             added case statements for each handler 
 * 
 *Thommaipillai     28/09/2021  Alpha 1.1   Finished state machine case statements
 *Kaushikmerin                              and added code to function with board
 * 		
 *******************************************************************************/
 
#include <xc.h>
#include "Tick_core.h"
#include <stdio.h>
#include "initBoard.h"
#include "encoder.h"

    
int main( void){
    
    initIO();
    initLCD();

    while(1){
        
        task1();
        //delay_us(100);
        idleTask();
        
    }

}// main

