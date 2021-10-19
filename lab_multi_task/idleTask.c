#include "console32.h"
#include "Tick_core.h"
#include <stdio.h>
#include "initBoard.h"

#define DELAYTIME 10000

int count;

void idleTask() {


    if(count > DELAYTIME) {
    
        count = 0;
        LATAbits.LATA1 ^= 1;
    
    }   
    else {
    
        count++;
        //LATAbits.LATA1 ^= 1;
    
    }
}