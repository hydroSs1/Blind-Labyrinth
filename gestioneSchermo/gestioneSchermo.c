
#include "../GLCD/GLCD.h"
#include "../TouchPanel/TouchPanel.h"


void disegnaTasti( void ){
	
	int x_01 = 20; 
	int y_0 = 270;
	int x_11 = 100;
	int y_1 = 300;
	int x_02 = 140;
	int x_12 = 220;
	
	int i;
	
	for(i=0; i< 30; i++){
		LCD_DrawLine(x_01,y_0+i,x_11,y_0+i,0xFFFF);
		LCD_DrawLine(x_02,y_0+i,x_12,y_0+i,Yellow);
	
}
	GUI_Text(20, 280, (uint8_t *) " Restart ", Blue, White);
	GUI_Text(140, 280, (uint8_t *) " Clear ", Blue, Yellow);
	

	
}


void disegnaCella(int x, int y){
	
	int x0 = 7;       //bordo matrice lato x
	int y0 = 62;			//bordo matrice lato y
	int x1;
	int y1;
	
	int i;
	
	int posx;
	int posy;
	
	posx = x0 + x*15;
	posy = y0 + y*15;
	
	for (i=0; i<15;i++){
		LCD_DrawLine(posx,posy+i,posx+15,posy+i,Black);
	}
	
}

void disegnaMappa(){
	
	int x_0 = 7;
	int x_1 = 232;
	
	int i;
	
	int y_0 = 62;
	
	for(i=0; i< 195; i++){
		LCD_DrawLine(x_0,y_0+i,x_1,y_0+i,0xFFFF);
	
}



}

void stampaRobot(int x, int y, int direzione){
	
	int x0 = 7;       //bordo matrice lato x
	int y0 = 62;			//bordo matrice lato y
	
	int i;
	int z;
	int posx;
	int posy;
	
	posx = x0 + x*15;
	posy = y0 + y*15;
	
	switch(direzione){
		case 0: //destra
			
			posx = x0 + x*15;
			posy = y0 + y*15;
		
			for(i=0;i<7;i++){
				LCD_DrawLine(posx,posy+i,posx+2*i, posy+i,0x07E0);
				
				
				
			}
			
			LCD_DrawLine(posx,posy+7,posx+7*2,posy+7,0x07E0 );
			
			z=i;
			
			
			for(i=8;i<15;i++){
				LCD_DrawLine(posx,posy+i,posx+2*z, posy+i,0x07E0);
				z--;
				
			}
		
			break;
			
		case 1: //sud
			posx = x0 + x*15;
			posy = y0 + y*15;
			
			for(i=0;i<7;i++){
				LCD_DrawLine(posx+i,posy,posx+i, posy+2*i,0x07E0);
				
		
				
			}
			LCD_DrawLine(posx+7,posy,posx+7,posy+2*7,0x07E0 );
			
			
			z=i;
			
			
			for(i=8;i<15;i++){
				LCD_DrawLine(posx+i,posy,posx+i, posy+2*z,0x07E0);
				z--;
				
			}
			break;
			
		case 2: //sinistra
			
			posx = x0 + x*15 + 15;
			posy = y0 + y*15 ;
			
			for(i=0;i<7;i++){
				LCD_DrawLine(posx,posy+i,posx-2*i, posy+i,0x07E0);
				
				
				
			}
			
			LCD_DrawLine(posx,posy+7,posx-7*2,posy+7,0x07E0 );
			
			
			
			z=i;
			
			
			for(i=8;i<15;i++){
				LCD_DrawLine(posx,posy+i,posx-2*z, posy+i,0x07E0);
				z--;
				
			}
			
			break;
			
		case 3: //nord
			posx = x0 + x*15;
			posy = y0 + y*15+15;
			
			for(i=0;i<7;i++){
				LCD_DrawLine(posx+i,posy,posx+i, posy-2*i,0x07E0);
				
		
				
			}
			LCD_DrawLine(posx+7,posy,posx+7,posy-2*7,0x07E0 );
			
			
			z=i;
			
			
			for(i=8;i<15;i++){
				LCD_DrawLine(posx+i,posy,posx+i, posy-2*z,0x07E0);
				z--;
				
			}
			break;
			break;
		}
	
	}



void inizializzaSchermo(void){
	
	int i;

	int x_0 = 7;
	int x_1 = 232;
	
	int y_0 = 62;
	//int y_1 = 195+62;
	
	
	
	
	LCD_Clear(Blue);
	
	GUI_Text(55, 25, (uint8_t *) "Blind Labirinth", Blue, White);
	
	
	disegnaTasti();
	
	

	
	
	GUI_Text(20, 280, (uint8_t *) " Restart ", Blue, White);

	GUI_Text(140, 280, (uint8_t *) " Clear ", Blue, Yellow);
	/*
	for(i=0; i< 195; i++){
		LCD_DrawLine(x_0,y_0+i,x_1,y_0+i,0xFFFF);
	
}
*/
disegnaMappa();

GUI_Text(78, 130, (uint8_t *) "Touch to", Blue, White);
GUI_Text(78, 150, (uint8_t *) " Start a", Blue, White);
GUI_Text(78, 170, (uint8_t *) "New Game", Blue, White);

	
disegnaCella(14,12);


stampaRobot(7,7,3);
stampaRobot(6,8,2);
stampaRobot(8,8,0);
stampaRobot(7,9,1);


}



void StampaMatrice(){

		int pos_x_iniziale = 5;
		int pos_y_iniziale = 20;
	int pos_x_finale = 5;
		int pos_y_finale = 215;
		int i;
	
	for(i=0;i<16;i++){
		LCD_DrawLine(pos_x_iniziale,pos_y_iniziale,pos_x_finale, pos_y_finale,0x07E0);
		pos_x_finale= pos_x_finale +15;
		pos_x_iniziale = pos_x_iniziale +15;

	}
	
	pos_x_iniziale = 5;
	pos_y_iniziale = 20;
	pos_x_finale = 230;
	pos_y_finale = 20;
	
	for(i=0;i<14;i++){
		LCD_DrawLine(pos_x_iniziale,pos_y_iniziale,pos_x_finale, pos_y_finale,0x07E0);
		pos_y_finale= pos_y_finale +15;
		pos_y_iniziale = pos_y_iniziale +15;

	}


return;
}


void muoviRobot(int x, int y, int direzione){
	
	switch(direzione){
		
		case 0://destra
			break;
		case 1://sud
			break;
		case 2://sinistra
			break;
		case 3://nord
			break;
	}
	
	return;
}


