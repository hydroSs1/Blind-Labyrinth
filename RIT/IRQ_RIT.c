/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../led/led.h"
#include "../timer/timer.h"
#include "../labirinto/labirinto.h"
/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

volatile int down=0;

void RIT_IRQHandler (void)
{					
	static int select=0;
	static int position=0;
	static int count = 0;
	
	
	static int modalita = 0;                     	            									/* 0 = move             1= explore */          
	
	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	  //SUD
		/* Joytick Select pressed */
		count++;
		if(count == 1){
				switch(modalita){
					case 0:																			/*move*/
						init_timer(0,0x17D7840);
						enable_timer(0);
					break;
					case 1:																			/*explore */
						direzione = 1;
						valutaDistanza(pos_x,pos_y);
					break;
					default:
						break;
				}
	
	
	}
}
	else{
			count=0;
			disable_timer(0);
			reset_timer(0);
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	//sinistra
		/* Joytick Select pressed */
		count++;
		if(count == 1){
				switch(modalita){
					case 0:																			/*move*/
						init_timer(0,0x17D7840);
						enable_timer(0);
					break;
					case 1:																			/*explore */
						direzione = 2;
						valutaDistanza(pos_x,pos_y);
					break;
					default:
						break;
				}
	}
}
	else{
			count=0;
			disable_timer(0);
			reset_timer(0);
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	  //DIREZIONE destra
		/* Joytick Select pressed */
		count++;
		if(count == 1){
				switch(modalita){
					case 0:																			/*move*/
						init_timer(0,0x17D7840);
						enable_timer(0);
					break;
					case 1:																			/*explore */
						direzione = 0;
						valutaDistanza(pos_x,pos_y);
					break;
					default:
						break;
				}
	}
}
	else{
			count=0;
			disable_timer(0);
			reset_timer(0);
	}
	
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	 //nord
		/* Joytick Select pressed */
		count++;
		if(count == 1){
				switch(modalita){
					case 0:																			/*move*/
						init_timer(0,0x17D7840);
						enable_timer(0);
					break;
					case 1:																			/*explore */
						direzione = 3;
					break;
					default:
						break;
				}
	}
}
	else{
			count=0;
			disable_timer(0);
			reset_timer(0);
	}

	
	
	if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){																						/*alla pressione del tasto select cambia le modalità*/
		/* Joytick Select pressed */
		count++;
		if(count==1){
					if(modalita==0){     
						modalita=1;
						
					}
					else{								
						modalita = 0;
					}
				}
				

	}
	else{
			count=0;
	}
	
	/* button management */
	if(down!=0){ 
		if((LPC_GPIO2->FIOPIN & (1<<11)) == 0){	/* KEY1 pressed */
			down++;				
			switch(down){
				case 2:				/* pay attention here: please see slides 19_ to understand value 2 */
				if( position == 7){
					LED_On(0);
					LED_Off(7);
					position = 0;
				}
				else{
					LED_Off(position);
					LED_On(++position);
				}
					break;
				default:
					break;
			}
		}
		else {	/* button released */
			down=0;			
			NVIC_EnableIRQ(EINT1_IRQn);							 /* enable Button interrupts			*/
			LPC_PINCON->PINSEL4    |= (1 << 22);     /* External interrupt 0 pin selection */
		}
	}
	
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
