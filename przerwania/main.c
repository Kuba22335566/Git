#include "timer_interrupts.h"
#include "keyboard.h"
#include "led.h"

void Automat() {
    enum LedState{STOP, LED_LEFT, LED_RIGHT};
	
	  static enum LedState eLedState = STOP;
	
		switch(eLedState) {
		
		    case STOP:
				    if( eKeyboardRead() == BUTTON_0) {
					
					      eLedState = LED_LEFT;
				    } else if(eKeyboardRead() == BUTTON_2){
					
					      eLedState = LED_RIGHT;
				    } else {
					
					      eLedState = STOP;
				    }
			      break;
				
			  case LED_LEFT:
				  
				
				    if( eKeyboardRead() == BUTTON_1) {
					      eLedState = STOP;
				    } else {
					      LedStepLeft();
					      eLedState = LED_LEFT;
				    }
			      break;
		
			  case LED_RIGHT:
				  
				
				    if( eKeyboardRead() == BUTTON_1) {
					      eLedState = STOP;
				    } else {
					      LedStepRight();
					      eLedState = LED_RIGHT;
				    }
			      break;
			  }
}

int main(){
	
    LedInit();
    KeyBoardInit();
	
	  Timer0Interrupts_Init(20000, &Automat);
	  while(1) {

	  }
}
