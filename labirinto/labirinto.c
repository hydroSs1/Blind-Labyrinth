#include "labirinto.h"
//#include "../led/led.h"
#include "../timer/timer.h"
#include "stdint.h"
#include "../gestioneSchermo/gestioneSchermo.h"

int direzione;																											/* variabile globale che indica la direzione del movimento sulla mappa, 0 = destra, 1 = basso, 2 = sinistra, 3= alto */
int pos_x ;																													/* variabile globale che indica la pos del robot sull'asse x  */
int pos_y;																													/* variabile globale che indica la pos del robot sull'asse y  */
int ostacolo;  																											/* Variabile globale che indica se il robot si sta muovendo o meno */
int fine;
int avvio = 0;
int puntaUscita;


int mappa[13][15] ={
																 {2,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
																 {0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
																 {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
																 {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
																 {0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
																 {1,1,1,1,1,0,0,1,0,1,0,0,0,1,0},
																 {0,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
																 {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
																 {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0},
																 {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
																 {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
																 {1,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
																 {2,0,1,0,0,0,0,0,0,0,0,0,0,0,2}
												};

void start(void){																										/* inizializza le variabili del gioco */
	
direzione = 0;																											/* variabile globale che indica la direzione del movimento sulla mappa, 0 = destra, 1 = basso, 2 = sinistra, 3= alto */
pos_x = 7;																													/* variabile globale che indica la pos del robot sull'asse x inizializzata a 7 */
pos_y = 7;																													/* variabile globale che indica la pos del robot sull'asse y inizializzata a 7 */
ostacolo = 0;  																											/* variabile globale che indica se il robot si sta muovendo o meno */
fine = 0;																												
avvio = 1;																													/* variabile globale che segnala che il tasto di avvio è stato premuto */
puntaUscita = 0;

return;
}


void gira(void){																										/* funzione che cambia la direzione */
	
		int distanza;
	
		if(direzione < 3)																									/*una volta che ho fatto il giro completo da direzione = destra a direzione = alto, resetto la variabile per tornare a direzione = destra*/
				direzione = direzione + 1;
		else
				direzione = 0;
	
		distanza = valutaDistanza(pos_x, pos_y);
		blinkDistanza(distanza);
		
		return;
}


void muovi(void){
	int NR =13;
	int NC = 15;
	int distanza;
	
	switch (direzione) {
				case 0:																												/* direzione destra */
						if((pos_y+1) < NC){																				/* controllo di essere all'interno dei bordi della mappa */
								if(mappa[pos_x][pos_y+1]==0){													/* caso in cui la casella è libera => muovo il robot */
										pos_y = pos_y+1;
										ostacolo = 0;
										distanza =valutaDistanza(pos_x,pos_y);						/* il robot si è mosso => aggiorno la distanza dagli ostacoli */
										blinkDistanza(distanza);
										break;
										}
								if(mappa[pos_x][pos_y+1]==1){													/* caso in cui trovo un muro => il robot rimane fermo */
										ostacolo = 1;
										break;
										}
								if(mappa[pos_x][pos_y+1]==2){													/* caso in cui il robot arriva all'uscita */
										pos_y = pos_y+1;
										blinkVittoria();
										fine = 1;
										break;
										}
								}
						else{
								ostacolo = 1;																					/*	sono arrivato sul bordo della mappa => setto ostacolo a 1 */
								break;
								}			
					
		case 1:																														/* direzione basso */
					if((pos_x+1) < NR){																					/* controllo di essere all'interno dei bordi della mappa */
						if(mappa[pos_x+1][pos_y]==0){															/* caso in cui la casella è libera => muovo il robot */
							pos_x = pos_x +1;
							ostacolo = 0;
							distanza = valutaDistanza(pos_x,pos_y);									/* il robot si è mosso => aggiorno la distanza dagli ostacoli */		
							blinkDistanza(distanza);
							break;
							}
						if(mappa[pos_x+1][pos_y]==1){															/* caso in cui trovo un muro => il robot rimane fermo */
							ostacolo = 1;
							break;
							}
						if(mappa[pos_x+1][pos_y]==2){															/* caso in cui il robot arriva all'uscita */
							pos_x = pos_x+1;
							blinkVittoria();
							fine = 1;
							break;
							}
					}
					else{																												/* caso in cui ho colpito i bordi della mappa => mi fermo */
						ostacolo = 1;
						break;
					}	
					
		case 2:																													  /* direzione sinistra */
					if((pos_y-1) >= 0){																					/* controllo di essere all'interno dei bordi della mappa */
						if(mappa[pos_x][pos_y-1]==0){															/* caso in cui la casella è libera => muovo il robot */
							pos_y = pos_y -1;
							ostacolo = 0;
							distanza = valutaDistanza(pos_x,pos_y);									/* il robot si è mosso => aggiorno la distanza dagli ostacoli */		
							blinkDistanza(distanza);
							
							break;
							}
						if(mappa[pos_x][pos_y-1]==1){															/* caso in cui trovo un muro => il robot rimane fermo */
							ostacolo = 1;
							break;
							}
						if(mappa[pos_x][pos_y-1]==2){															/* caso in cui il robot arriva all'uscita */
							pos_y = pos_y-1;
							blinkVittoria();
							fine = 1;
							break;
							}
					}
					else{																												/* sono arrivato sul bordo della mappa => setto ostacolo a 1 */
						ostacolo = 1;
						break;
					}	
					
		case 3:
					if((pos_x-1) >= 0){																					/* controllo di essere all'interno dei bordi della mappa */
						if(mappa[pos_x-1][pos_y]==0){															/* caso in cui la casella è libera => muovo il robot */
							pos_x = pos_x -1;
							ostacolo = 0;
							distanza = valutaDistanza(pos_x,pos_y);									/* il robot si è mosso => aggiorno la distanza dagli ostacoli */		
							blinkDistanza(distanza);
							break;
							}
						if(mappa[pos_x-1][pos_y]==1){															/* caso in cui trovo un muro => il robot rimane fermo */
							ostacolo = 1;
							break;
							}
						if(mappa[pos_x-1][pos_y]==2){															/* caso in cui il robot arriva all'uscita */
							pos_x = pos_x-1;
							blinkVittoria();
							fine = 1;
							break;
							}
					}
					else{																												/* sono arrivato sul bordo della mappa => setto ostacolo a 1 */
						ostacolo = 1;
						break;
					}		
		}
		return;
		
	}

int valutaDistanza(int x, int y){
	
		int distanza = 0;																									/* la distanza è inizializzata ad 0 e sarà incrementata finchè non si troverà un ostacolo */
		int NR =13;
		int NC = 15;
		
		switch(direzione){																								/* in base alla direzione si sceglie in che direzione calcolare la distanza */
			case 0:
				while(mappa[x][y+1]!=1 && y+1< NC){														/* finchè non incontro un ostacolo o il bordo della mappa incremento la distanza */

						distanza++;
						y = y+1;																									/* aggiorno la coordinata su cui mi sto muovendo */
				}
				break;
			case 1:
				while(mappa[x+1][y]!=1 && x+1< NR){
						distanza++;
						x = x+1;
				}
				break;
			case 2:
				while(mappa[x][y-1]!=1 && y-1>0){
						distanza++;
						y = y-1;
				}
				break;
			case 3:
				while(x> 0 && mappa[x-1][y]!=1){
						distanza++;
						x = x-1;
				}
				break;
		}
		
		if(mappa[x][y]==2){																							/*una volta terminato il controllo verifico se l'ultima casella idonea è l'uscita*/
					puntaUscita=1;}																						/* in quel caso setto il flag a 1 */
				else{
					puntaUscita = 0;
				}
		
		return distanza;
		}


void blinkDistanza(int distanza){
	
	if(puntaUscita ==1){
		disable_timer(2);
		reset_timer(2);
		return;}

	if(distanza>5){																															/*distanza maggiore di 5 blocchi => no blink*/
			disable_timer(2);																												/*fermo il timer e lo resetto */
			reset_timer(2);
			return;
			}
	if(distanza<=5 && distanza>=3){																							/*distanza compresa tra 5 e 3 => blink a 2 Hz */
			disable_timer(2);																												/*fermo il timer */
			reset_timer(2);																													/*resetto il timer */
			init_timer(2,0x5F5E10);																									/*inizializzo il timer alla nuova frequenza*/
			enable_timer(2);																												/*faccio partire il timer*/
			return;
			}
	if(distanza <= 2 && distanza >= 1){			                                  	/*distanza compresa tra 2 e 1 => blink a 4 Hz */
			disable_timer(2);
			reset_timer(2);
			init_timer(2,0x2FAF08);           
			enable_timer(2);
			return;
		}
	if(distanza==0){																														/*distanza uguale a 0 => blink a 8 Hz */
			disable_timer(2);
			reset_timer(2);
			init_timer(2,0x7D784);
			enable_timer(2);
			return;
		}
}


void blinkVittoria(void){
			
		init_timer(3,0xBEBC20); 																										/* inizializzo il timer per lampeggiare ogni 0.5s per avere una frequenza di blink di 1Hz => 0.5s*25*10(^6)= 12500000 (0xBEBC20 in decimale)*/
		disable_timer(0);         																									/* disabilito il timer che fa lampeggiare il led di movimento */ 
		disable_timer(1);
		disable_timer(2);																														/* disabilito il timer che fa lampeggiare i led di direzione */
	
		enable_timer(3);																														/* attivo il timer che fa lampeggiare tutti i led*/
	
		return;
}

void muoviSuSchermo(int x, int y, int direzione){




}
