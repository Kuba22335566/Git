#include <LPC21xx.H>
#include "led.h"

#define mLED0_bm (1<<16)
#define mLED1_bm (1<<17)
#define mLED2_bm (1<<18)
#define mLED3_bm (1<<19)



void LedInit(){
  
    IO1DIR |= (mLED0_bm|mLED1_bm|mLED2_bm|mLED3_bm);
    IO1CLR = mLED0_bm|mLED1_bm|mLED2_bm|mLED3_bm;
    IO1SET = mLED0_bm;
  
}

void LedOn (unsigned char ucLedIndeks)
{
	
	  IO1CLR = mLED0_bm|mLED1_bm|mLED2_bm|mLED3_bm;
	
	  switch(ucLedIndeks)
	  {
		    case 0:
				    IO1SET = mLED0_bm;
				    break;
				case 1:
					  IO1SET = mLED1_bm;
				    break;
				case 2:
					  IO1SET = mLED2_bm;
				    break;
				case 3:
					  IO1SET = mLED3_bm;
				    break;
				default:
					  break;
		}
				
}

enum StepDirection{LEFT,RIGHT};

void LedStep(enum StepDirection eDirection)
{
	 static unsigned char ucLedIndex = 0;
	
	 if(eDirection == LEFT)
	 {
	     ucLedIndex = (ucLedIndex+1)%4;		 
	 }
	 else if(eDirection == RIGHT)
	 {
			 ucLedIndex = (ucLedIndex+3)%4;
	 }
	 LedOn(ucLedIndex);	 
}

void LedStepLeft(void)
{
	 LedStep(LEFT);
}

void LedStepRight(void)
{
	  LedStep(RIGHT);
}
