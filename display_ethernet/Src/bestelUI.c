/*
 * bestelUI.c
 *
 *  Created on: 4-dec.-2016
 *  Author: Robbe Goovaerts
 */

#include "bestelUI.h"
#include "math.h"


menu_struct *headMenu[4];
menu_struct *currMenu[4];
int hoofdMenuIndex = 0;
int onderMenuIndex = 0;
double totaalPrijs = 0;
char cnaam[8];
char zichtbaarItem[20];
int zichtbaarID;
int zichtbaarOnderID;
int aantalDetail = 0;
double prijsDetail = 0;

menu_struct* createList(char data[], int id, int lijstID, int startX, int startY, int breedte, int hoogte, void (*functie)(void), int subID)
{
	menu_struct *ptr = (menu_struct*)malloc(sizeof(menu_struct));
	if(ptr == NULL)
	{
		BSP_LCD_Clear(LCD_COLOR_RED);
		BSP_LCD_SetBackColor(LCD_COLOR_RED);
		BSP_LCD_SetFont(&Font24);
		BSP_LCD_DisplayStringAt(0, 5, (uint8_t*)"Niet genoeg geheugen!", CENTER_MODE);
		while(1)
		{}
	}

	strcpy(ptr->data, data);
	ptr->id = id;
	ptr->breedte = breedte;
	ptr->hoogte = hoogte;
	ptr->startX = startX;
	ptr->startY = startY;
	ptr->next = NULL;
	ptr->functie = functie;
	ptr->subID = subID;
	headMenu[lijstID] = currMenu[lijstID] = ptr;
	return ptr;
}

menu_struct* addToList(char data[], int id, int lijstID, int startX, int startY, int breedte, int hoogte, void (*functie)(void), int subID)
{
	if(headMenu[lijstID] == NULL)
	{
		return(createList(data, id, lijstID, startX, startY, breedte, hoogte, functie, subID));
	}

	menu_struct *ptr = (menu_struct*)malloc(sizeof(menu_struct));
	if(ptr == NULL)
	{
		BSP_LCD_Clear(LCD_COLOR_RED);
		BSP_LCD_SetBackColor(LCD_COLOR_RED);
		BSP_LCD_SetFont(&Font24);
		BSP_LCD_DisplayStringAt(0, 5, (uint8_t*)"Niet genoeg geheugen!", CENTER_MODE);
		while(1)
		{}
	}

	strcpy(ptr->data, data);
	ptr->id = id;
	ptr->breedte = breedte;
	ptr->hoogte = hoogte;
	ptr->startX = startX;
	ptr->startY = startY;
	ptr->functie = functie;
	ptr->subID = subID;
	ptr->next = NULL;

	currMenu[lijstID]->next = ptr;
	currMenu[lijstID] = ptr;

	return ptr;
}

void vsetDevicename( char name[8] )
{
	int i;
	for(i=0;i<8;i++)
	{
		cnaam[i]=name[i];
	}
	cnaam[i]='\0';
}

void vprintStartscherm( int xduur )
{
	BSP_LCD_Clear( 0xff5495ff );
	BSP_LCD_SetTextColor( 0xffffffff );
	BSP_LCD_SetBackColor( 0xff5495ff );
	BSP_LCD_SetFont( &Font24 );
	BSP_LCD_DisplayStringAt( 0, 15, (uint8_t*)"Bestelsysteeem V1.0", CENTER_MODE );
	BSP_LCD_SetFont( &Font20 );
	BSP_LCD_DisplayStringAt( 0, 60, (uint8_t*)"Embedded systems", CENTER_MODE );
	BSP_LCD_DisplayStringAt( 0, 100, (uint8_t*)"Robbe Goovaerts", CENTER_MODE );
	HAL_Delay(xduur);
}

void vprintWachtenVerbinding( void )
{
	BSP_LCD_Clear( 0xff5495ff );
	BSP_LCD_SetTextColor( 0xffffffff );
	BSP_LCD_SetBackColor( 0xff5495ff );
	BSP_LCD_SetFont( &Font24 );
	BSP_LCD_DisplayStringAt( 0, 15, (uint8_t*)"Wachten op verbinding...", CENTER_MODE );
}

void vprintVerbonden( int xduur)
{
	BSP_LCD_Clear(0xff00ff00);
	BSP_LCD_SetTextColor( 0xffffffff );
	BSP_LCD_SetBackColor( 0xff00ff00 );
	BSP_LCD_SetFont( &Font24 );
	BSP_LCD_DisplayStringAt( 0, 15, (uint8_t*)"Verbonden!", CENTER_MODE );
	HAL_Delay( xduur );
}

void vinitSideMenu( void )
{
	menu_struct *localCurr;
	BSP_LCD_Clear( 0xff5495ff );
	BSP_LCD_SetTextColor( LCD_COLOR_WHITE );
	BSP_LCD_SetBackColor( 0xff5495ff );
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_DrawLine( 320, 0, 320, 272 );
	BSP_LCD_DisplayStringAt( 0 , 5, (uint8_t*)cnaam, RIGHT_MODE );

	//Knoppen instellen
	addToList("UP", 0, 2, 325, 32, 45, 35, &vmenuUP, 0);
	addToList("DOWN", 1, 2, 325, 72, 45, 35, &vmenuDOWN, 0);
	addToList("TERUG", 2, 2, 390, 32, 60, 35, &vmenuTERUG, 0);

	//Knoppen tekenen
	localCurr = headMenu[2];

	while(localCurr!=NULL)
	{
		BSP_LCD_SetBackColor( 0xff54ccff );
		BSP_LCD_SetTextColor( 0xff54ccff );
		BSP_LCD_FillRect(localCurr->startX+1, localCurr->startY+1, localCurr->breedte-1, localCurr->hoogte-1);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_DrawRect(localCurr->startX, localCurr->startY, localCurr->breedte, localCurr->hoogte);
		BSP_LCD_DisplayStringAt(localCurr->startX+1, localCurr->startY+8, (uint8_t*)localCurr->data, LEFT_MODE);
		localCurr = localCurr->next;
	}
	vprintTotaalPrijs();
}

void vprintHoofdmenu()
{
	vclearMenuSection();
	menu_struct *localCurr = headMenu[0];
	int printCounter = 0;
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetBackColor( 0xff5495ff );
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	strcpy(zichtbaarItem, "Hoofdmenu");

	//Tittel adrukken
	BSP_LCD_DisplayStringAt(20, 12, (uint8_t*)zichtbaarItem, LEFT_MODE);

	//Items adrukken
	BSP_LCD_SetBackColor(0xff54ccff);
	while((localCurr!=NULL) & (localCurr->id < hoofdMenuIndex))
	{
		localCurr=localCurr->next;
	}
	while((localCurr!=NULL) & (printCounter<6))
	{
		BSP_LCD_SetTextColor(0xff54ccff);
		BSP_LCD_FillRect(5+1, 32 + 40*printCounter+1, 310-1, 35-1);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_DrawRect(5, 32 + 40*printCounter, 310, 35);
		BSP_LCD_DisplayStringAt(20, 42 + 40*printCounter, (uint8_t*)localCurr->data, LEFT_MODE);

		//Locatie van knop wegschrijven naar struct voor TS functies
		localCurr->startX = 5;
		localCurr->startY = 32 + 40 * printCounter;
		localCurr->breedte = 310;
		localCurr->hoogte = 35;

		localCurr=localCurr->next;
		printCounter++;
	}
}

void vprintOndermenu()
{
	vclearMenuSection();
	menu_struct *localCurr = headMenu[1];
	int printCounter = 0;
	BSP_LCD_SetFont(&Font16);
	BSP_LCD_SetBackColor( 0xff5495ff );
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	strcpy(zichtbaarItem, "Ondermenu");

	//Tittel adrukken
	BSP_LCD_DisplayStringAt(20, 12, (uint8_t*)zichtbaarItem, LEFT_MODE);


	//Items adrukken
	BSP_LCD_SetBackColor(0xff54ccff);
	while((localCurr!=NULL) & (localCurr->id < onderMenuIndex))
	{
		localCurr=localCurr->next;
	}
	while((localCurr!=NULL) & (printCounter<6))
	{
		BSP_LCD_SetTextColor(0xff54ccff);
		BSP_LCD_FillRect(5+1, 32 + 40*printCounter+1, 310-1, 35-1);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_DrawRect(5, 32 + 40*printCounter, 310, 35);
		BSP_LCD_DisplayStringAt(20, 42 + 40*printCounter, (uint8_t*)localCurr->data, LEFT_MODE);

		//Locatie van knop wegschrijven naar struct voor TS functies
		localCurr->startX = 5;
		localCurr->startY = 32 + 40 * printCounter;
		localCurr->breedte = 310;
		localCurr->hoogte = 35;

		localCurr=localCurr->next;
		printCounter++;
	}
}

void vmenuDOWN()
{
	if(strcmp("Hoofdmenu", zichtbaarItem))
	{
		onderMenuIndex++;
		vprintOndermenu();
	}
	else
	{
		hoofdMenuIndex++;
		vprintHoofdmenu();
	}
}

void vmenuUP()
{
	if(strcmp("Hoofdmenu", zichtbaarItem))
	{
		onderMenuIndex--;
		if(onderMenuIndex<0)
		{
			onderMenuIndex = 0;
		}
		vprintOndermenu();
	}
	else
	{
		hoofdMenuIndex--;
		if(hoofdMenuIndex<0)
		{
			hoofdMenuIndex=0;
		}
		vprintHoofdmenu();
	}
}

void vmenuTERUG( void )
{
	if(strcmp("Hoofdmenu", zichtbaarItem))
	{
		vclearOndermenu();
		vprintHoofdmenu();
	}
}

void vclearMenuSection()
{
	menu_struct *localCurr = headMenu[0];

	BSP_LCD_SetTextColor(0xff5495ff);
	BSP_LCD_FillRect(0, 0, 319, 272);

	while(localCurr!=NULL)
	{
		localCurr->breedte = 0;
		localCurr->hoogte = 0;
		localCurr->startX = 0;
		localCurr->startY = 0;
		localCurr = localCurr->next;
	}

	localCurr = headMenu[1];
	while(localCurr!=NULL)
	{
		localCurr->breedte = 0;
		localCurr->hoogte = 0;
		localCurr->startX = 0;
		localCurr->startY = 0;
		localCurr = localCurr->next;
	}
}

void getSubmenu( void )
{

}

void vclearOndermenu( void )
{
	menu_struct *localCurr = currMenu[1];
	menu_struct *nextBuffer;

	while(localCurr!=NULL)
	{
		nextBuffer = localCurr->next;
		free(localCurr);
		localCurr = nextBuffer;
	}
	currMenu[1] = NULL;
	headMenu[1] = NULL;
}

void vprintTotaalPrijs( void )
{
	char prijsBuffer[32];

	BSP_LCD_SetBackColor( 0xff5495ff );
	BSP_LCD_SetTextColor( LCD_COLOR_WHITE );

	sprintf(prijsBuffer, "%4d,%02d EURO", (int)totaalPrijs, ((int)(totaalPrijs*100)) % 100);

	BSP_LCD_DisplayStringAt(330, 140, (uint8_t*)"TOTAAL:", LEFT_MODE);
	BSP_LCD_DisplayStringAt(330, 180, (uint8_t*)prijsBuffer, LEFT_MODE);
}

void vsetDetailPrice( char* prijs )
{
	char cprijsBuffer[64];

	BSP_LCD_SetBackColor( 0xff5495ff );
	BSP_LCD_SetTextColor( LCD_COLOR_WHITE );

	strcpy(cprijsBuffer, prijs);
	strcat(cprijsBuffer, " EURO");

	BSP_LCD_DisplayStringAt(20, 140, (uint8_t*)zichtbaarItem, LEFT_MODE);
	BSP_LCD_DisplayStringAt(20, 160, (uint8_t*)cprijsBuffer, LEFT_MODE);
}

void venableBestelopties( void )
{
	menu_struct *localCurr = headMenu[3];
	int foundPlus = 0, foundMin = 0, foundBestellen = 0;

	while(localCurr!=NULL)
	{
		if(!strcmp(localCurr->data, "+"))
		{
			foundPlus = 1;
		}
		if(!strcmp(localCurr->data, "-"))
		{
			foundMin = 1;
		}
		if(!strcmp(localCurr->data, "BESTELLEN"))
		{
			foundBestellen = 1;
		}
		localCurr = localCurr->next;
	}

	if(foundPlus==0)
	{
		addToList("+", 99, 3, 130, 180, 30, 30, &vaantalPlus, 0);
	}
	if(foundMin==0)
	{
		addToList("-", 99, 3, 170, 180, 30, 30, &vaantalMin, 0);
	}
	if(foundBestellen==0)
	{
		addToList("BESTELLEN", 99, 3, 130, 220, 120, 30, &vbestellingToevoegen, 0);
	}


	aantalDetail = 0;

	localCurr = headMenu[3];

	BSP_LCD_SetBackColor(0xff54ccff);
	while((localCurr!=NULL))
	{
		BSP_LCD_SetTextColor(0xff54ccff);
		BSP_LCD_FillRect(localCurr->startX+1, localCurr->startY+1, localCurr->breedte-1, localCurr->hoogte-1);
		BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
		BSP_LCD_DrawRect(localCurr->startX, localCurr->startY, localCurr->breedte, localCurr->hoogte);
		BSP_LCD_DisplayStringAt(localCurr->startX + 6, localCurr->startY+8, (uint8_t*)localCurr->data, LEFT_MODE);

		localCurr=localCurr->next;
	}
}

void vsetAantal( void )
{
	char caantal[16];

	BSP_LCD_SetBackColor(0xff5495ff);
	BSP_LCD_SetTextColor(0xff5495ff);
	sprintf(caantal, "%d", aantalDetail);

	BSP_LCD_FillRect(19, 185, 40, 15);
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(20, 186, (uint8_t*)caantal, LEFT_MODE);
}

void vaantalMin( void )
{
	aantalDetail--;
	if(aantalDetail<0)
	{
		aantalDetail = 0;
	}
	vsetAantal();
}

void vaantalPlus( void )
{
	aantalDetail++;
	vsetAantal();
}

void vbestellingToevoegen( void )
{
	totaalPrijs += 1 * aantalDetail;
	vprintTotaalPrijs();
}

