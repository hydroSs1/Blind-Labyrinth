


extern int pos_x;
extern int pos_y;
extern int direzione;
extern int ostacolo;
extern int avvio;
extern int fine;
extern int mappa[13][15];
extern int puntaUscita;


void start(void);
void gira(void);
void muovi(void);
int valutaDistanza(int x, int y);
void blinkDistanza(int distanza);
void blinkVittoria(void);






