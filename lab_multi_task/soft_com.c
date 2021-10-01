#include "console32.h"
#include "Tick_core.h"
#include "soft_com.h"
//#include "queue.h"

#define BAUD_RATE 200000
//#define TICK_SECOND 80000000
#define TIMEOUT_START   BAUD_RATE/2
#define TIMEOUT_STOP    BAUD_RATE/4





//static QueueHandle_t* queue;
static int32_t lastTick;
int count = 0;

/* Initializes resources */ 

void initSoftCom(void){ 
    lastTick=TickGet();  
    
  
//    IFS1bits.U2RXIF = 0;
//    while( U2STAbits.URXDA ){
//        cChar= U2RXREG;// Latest ASCII code received
//        xQueueSendToBack( queue, &cChar);
    //return 0;
} 

 

/* Public interface to communicate with this task */ 

int getCnt(void){ 
    if (count==9){
    count =1;}

return count; 

} 

 

 

void softComTask(void) { 
//int32_t rx=0;
//int32_t delay = 10; //temporary vale for counter
static char cChar[]="three";
//int size = sizeof(cChar);
static int i;

static int size = 5;
static int new_value = 'a';
static int acsii_value;
//int mask_acsii_value;

//int serial[9];

//queue = xQueueCreate(1);



 	static enum {SM_POLL, SM_POLL_HANDLER, SM_RETR_ENTRY, SM_START_BIT_ENTRY,SM_START_BIT_HANDLER, SM_SEND_BITS_ENTRY,SM_SEND_BITS_HANDLER, SM_STOP_BIT_ENTRY, SM_STOP_BIT_HANDLER} state= SM_SEND_BITS_ENTRY;

 

    //////////////SM_POLL/////////////////
    switch(state){
    
        case SM_POLL_HANDLER:
//            if (xQueueReceive(queue,&rx) == 0){
//                //do something whenever a new datum is received
//            } 
           
            break;    
            
            
    //////////////SM_RETR/////////////////        
        case SM_RETR_ENTRY:
            //state = SM_POLL_HANDLER;
            
                if (i<=size){ //temporary counter
                    cChar[i] = new_value;
                    i++;
                    state = SM_RETR_ENTRY;  
                }
                else state = SM_POLL_HANDLER;
            
           
            break;
            
        
    //////////////SM_START_BIT/////////////////          
        case SM_START_BIT_ENTRY:
            LATFbits.LATF5 = 0; 
            state = SM_START_BIT_HANDLER;
            break;
              
            
            
            

            
            
            
    //////////////SM_SEND_BITS/////////////////  
            
        case SM_SEND_BITS_ENTRY:
            acsii_value = new_value;
            count = 1;
            LATFbits.LATF5 = acsii_value & 0x01; //mask
            state = SM_SEND_BITS_HANDLER;   
            break;

            
            
        case SM_SEND_BITS_HANDLER:
         if(TickDiff(lastTick)>= TIMEOUT_START){    
            lastTick=TickGet();
            
            if( count < 8){
                
                acsii_value = acsii_value>>1; //shift
                LATFbits.LATF5 = acsii_value & 0x01; //mask
                count++;
                state = SM_SEND_BITS_HANDLER;
            }
            
            state = SM_STOP_BIT_ENTRY;
         }
         else {
                lastTick = TickGet();
                state = SM_STOP_BIT_ENTRY;
                SM_SEND_BITS_HANDLER;
                break;  
                
            }
     
        
            
            
    //////////////SM_STOP_BIT/////////////////                
        case SM_STOP_BIT_ENTRY:
            LATFbits.LATF5 = 1; 
            state = SM_STOP_BIT_HANDLER;
            break;
            
        case SM_STOP_BIT_HANDLER:
            if(TickDiff(lastTick)>= TIMEOUT_STOP){
                lastTick=TickGet();
                state = SM_RETR_ENTRY;
            }
            else 
                state = SM_STOP_BIT_HANDLER;
            break;


 

} // end of case  

}// end of softComTask 

 

