/*
 * cmd.c
 *
 *  Created on: 30-nov.-2016
 *  Author: Robbe Goovaerts
 */

#include "cmd.h"

char *pvGeheugen[MAX_LEN_GEHEUGEN];
int xWriteLocation = 0;
int xBottomLine = 10;

/*
 * Deze functie initaliseert het display.
 */
void voidLcdInit( void )
{
	/* LCD Initialization */
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
	/* Enable the LCD */
	BSP_LCD_DisplayOn();
}

/*------------------------------------------------------------------------*/

/*
 * Deze functie zet alles klaar om het display te kunnen gebruiken als cmd.
 */
void voidCmdInit( void )
{
	/* Select the LCD Background Layer  */
	BSP_LCD_SelectLayer(0);
	/* Clear the Background Layer */
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	/* Some sign */
	BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font16);
}

/*------------------------------------------------------------------------*/

/*
 * Deze functie pusht één regel naar het scherm
 */

void voidCmdWrite( char *input, int len )
{
	//Geheugen alloceren
	char *buffer = (char*)calloc(len, sizeof(char));

	//Input string wegschrijven naar die geheugenplaats
	buffer = input;

	//Input wegschrijven naar geheugen array
	pvGeheugen[xWriteLocation] = buffer;
	xWriteLocation++;

	//Scherm herschrijven
	voidRefreshDisplay();
}

/*------------------------------------------------------------------------*/

/*
 * Deze functie schrijft het hele display terug naar het scherm
 */

void voidRefreshDisplay( void )
{
	int xTeller = xWriteLocation - 1;
	int xLijnTeller;

	//Het scherm leegmaken
	BSP_LCD_Clear(LCD_COLOR_BLACK);

	//Onderste schrijflijn berekenen
	if(xTeller<=xBottomLine)
	{
		xLijnTeller = xTeller;
	}
	else
	{
		xLijnTeller = xBottomLine;
	}

	//Beeld lijn per lijn wegschrijven. Van onderen te beginnen.
	while(xLijnTeller >= 0)
	{
		BSP_LCD_DisplayStringAtLine(xLijnTeller, (uint8_t*)pvGeheugen[xTeller]);
		xTeller--;
		xLijnTeller--;
	}
}






