#include "console32.h"
#include "Tick_core.h"

#define BAUD_RATE 200000
//#define TICK_SECOND 80000000
#define TIMEOUT_START   0
#define TIMEOUT_STOP     

 static int32_t lastTick;
 int count=0;
 
/* Initializes resources */ 

void initSoftCom(void){ 
    lastTick=TickGet();  
    return 0;

 

} 

 

/* Public interface to communicate with this task */ 

int getCnt(void){ 

return count; 

} 

 

 

void softComTask(void) { 

    			 

 	static enum {SM_POLL, SM_POLL_HANDLER, SM_RETR_ENTRY, SM_START_BIT_ENTRY,SM_START_BIT_HANDLER, SM_SEND_BITS_ENTRY,SM_SEND_BITS_HANDLER, SM_STOP_BIT_ENTRY, SM_STOP_BIT_HANDLER} state= SM_POLL; 

 

    //////////////SM_POLL/////////////////
        case SM_POLL_HANDLER:
            
        
    //////////////SM_RETR/////////////////        
        case SM_RETR_ENTRY:
       
        
    //////////////SM_START_BIT/////////////////          
        case SM_START_BIT_ENTRY:
              
        case SM_START_BIT_HANDLER:
             if(TickDiff(lastTick)>= TIMEOUT_START){
                state = SM_SEND_BITS_ENTRY;
            }
            else 
                state = SM_STOP_BIT_HANDLER;
            break;
            
            
            
    //////////////SM_SEND_BITS/////////////////            
        case SM_SEND_BITS_ENTRY:
            lastTick=TickGet();
            
        case SM_SEND_BITS_HANDLER:
            if(count == 8){
                lastTick=TickGet();
                state = SM_STOP_BIT_ENTRY;
            }
            else if (count < 8)
                state = SM_SEND_BITS_ENTRY;
            else
                state = SM_SEND_BITS_HANDLER;
			break;  
            
            
    //////////////SM_STOP_BIT/////////////////                
        case SM_STOP_BIT_ENTRY:
            
        case SM_STOP_BIT_HANDLER:
            if(TickDiff(lastTick)>= TIMEOUT_STOP){
                state = SM_RETR_ENTRY;
            }
            else 
                state = SM_STOP_BIT_HANDLER;
            break;


 

} // end of case  

}// end of softComTask 

 
