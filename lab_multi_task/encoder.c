#include "console32.h"
#include "Tick_core.h"
#include <stdio.h>

//#define S3  PORTDbits.RD6
//#define S6  PORTDbits.RD7
//#define TICK_SECOND 80000000
//#define TIMEOUT     TICK_SECOND/10

static int32_t lastTick;
int cnt;
char buf[100];

#define PBstate PORTDbits.RD6
#define encoderA PORTDbits.RD0
#define encoderB PORTBbits.RB0


//void valueCheck(void){
//     
//    fprintf2(C_UART1, "Starting\n");
//    if(encoderA == 0 && encoderB == 0){
//        
//       
//        
//    }
//    
//}

void task1(void) {
 	static enum {SM_INITIATE, SM0_HANDLER,SM1_HANDLER,SM2_HANDLER,SM3_HANDLER} state = SM_INITIATE;

   	switch(state){
        case SM_INITIATE:
            if(encoderA == 0 && encoderB == 0){
        
                state = SM0_HANDLER;
         
            }
            if(encoderA == 0 && encoderB == 1){
        
                state = SM1_HANDLER;
        
            }
            if(encoderA == 1 && encoderB == 0){
        
                state = SM2_HANDLER;
        
            }
            if(encoderA == 1 && encoderB == 1){
        
                state = SM3_HANDLER;
        
            }
            break;
		case SM0_HANDLER:
           // fprintf2(C_UART1, "SM0\n");
            if(PBstate == !1) {
                
                cnt = 0;
                  
            }
            else if(encoderA == 0 && encoderB == 1) {
                
                cnt++;
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM1_HANDLER;
                
            }
            else if(encoderA == 1 && encoderB == 0){
                
                cnt--;
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM2_HANDLER;
                
            }
			break;
		case SM1_HANDLER:
            //fprintf2(C_UART1, "SM1\n");
            if(PBstate == !1) {
                
                cnt = 0;
                
            }
            else if(encoderA == 1 && encoderB == 1) {
                
                cnt++;
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM3_HANDLER;
                
            }
            else if(encoderA == 0 && encoderB == 0){
                
                cnt--;
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM0_HANDLER;
                
            }
			break;       
        case SM2_HANDLER:
            //fprintf2(C_UART1, "SM2\n");
            if(PBstate == !1) {
                
                cnt = 0;
                
            }
            else if(encoderA == 0 && encoderB == 0) {
                
                cnt++;
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM0_HANDLER;
                 
            }
            else if(encoderA == 1 && encoderB == 1){
                
                cnt--; 
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM3_HANDLER;
                
            }
			break;
		case SM3_HANDLER:
            //fprintf2(C_UART1, "SM3\n");
            if(PBstate == !1) {
                
                cnt = 0;
                
            }
            else if(encoderA == 1 && encoderB == 0) {
                
                cnt++;
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM2_HANDLER;
                
            }
            else if(encoderA == 0 && encoderB == 1){
                
                cnt--;
                sprintf(buf, "Counter: %d", cnt);
                fprintf2(C_LCD, buf);
                state = SM1_HANDLER;
                
            }
			break;
	}
}