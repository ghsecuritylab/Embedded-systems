/*
 * bestelUI.h
 *
 *  Created on: 4-dec.-2016
 *      Author: robbe
 */

#ifndef BESTELUI_H_
#define BESTELUI_H_

#include "stm32f7xx_hal.h"
#include "usb_device.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_sdram.h"
#include "stm32746g_discovery_ts.h"
#include "string.h"


typedef struct hoofdmenu_struct
{
	char data[30];
	int id;
	int subID;
	int startX;
	int startY;
	int breedte;
	int hoogte;
	void (*functie)( void );
	struct hoofdmenu_struct *next;
}menu_struct;

extern menu_struct *headMenu[4];
extern menu_struct *currMenu[4];
extern int hoofdMenuIndex;	//Id van het eerste hoofdmenuitem dat men moet laten zien
extern int onderMenuIndex; //Id van het eerste ondermenuitemen dat men moet laten zien
extern double totaalPrijs; //Totaale prijs van de bestelling
extern char cnaam[8];
extern char zichtbaarItem[20];
extern int zichtbaarID;
extern int zichtbaarOnderID;
extern int aantalDetail;
extern double prijsDetail;

/*
 * 0 -> hoofdmenu
 * 1 -> ondermenu
 * 2 -> sidemenu
 * 3 -> bestelopties
 */

void vprintStartscherm( int xduur );
void vprintWachtenVerbinding( void );
void vprintVerbonden(int xduur);
void vinitSideMenu( void );
void vsetDevicename( char name[8] );
void vprintHoofdmenu( void );
void vprintOndermenu( void );
void cpmenusectionGeklikt( TS_StateTypeDef *TSStatus );
void vmenuDOWN( void );
void vmenuUP( void );
void vmenuTERUG( void );
void vclearMenuSection( void );
void getSubmenu( void );
void vclearOndermenu( void );
void vprintTotaalPrijs( void );
void vsetDetailPrice( char *prijs );
void venableBestelopties( void );
void vsetAantal( void );
void vaantalMin( void );
void vaantalPlus( void );
void vbestellingToevoegen( void );

menu_struct* addToList(char data[], int id, int lijstID, int startX, int startY, int breedte, int hoogte, void (*functie)(void), int subID);
menu_struct* createList(char data[], int id, int lijstID, int startX, int startY, int breedte, int hoogte, void (*functie)(void), int subID);


#endif /* BESTELUI_H_ */
