//==============================================================================
//
// Title:		Simon Gmae
// Purpose:		A short description of the application.
//
// Created on:	17/06/2022 at 19:44:19 by Aleksey Zgeria.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include <time.h>
#include <stdio.h>
#include "Simon Gmae.h"
#include "toolbox.h"

//==============================================================================
// variables For Functions

int printf(const char *format, ...);
int rand(void);

//==============================================================================
// global variables
int levelCount=1,gameMode=1; 
int numSeqRandom[100],userSeqInput[100]; ///shoud be dynimc arry 
int gameCount=-1;
int seqCount=0;
int userInput;
//==============================================================================
// Static global variables

static int mainPanel = 0;
static int gamePanel = 0;
static int aboutPanel = 0;
static int gameLantheDefulet = 100;


//==============================================================================
// Static functions

int timeOut( int seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}

    return  1;
}

int setBtnToPlay(void)
{
	
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_GREEN, ATTR_CTRL_MODE, VAL_VALIDATE);
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_BLUE,ATTR_CTRL_MODE, VAL_VALIDATE);
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_YELLOW, ATTR_CTRL_MODE,VAL_VALIDATE);
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_RED, ATTR_CTRL_MODE,VAL_VALIDATE);
	return 1;
}

int setBtnToLight(void)
{
	
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_GREEN, ATTR_CTRL_MODE, VAL_INDICATOR);
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_BLUE,ATTR_CTRL_MODE, VAL_INDICATOR);
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_YELLOW, ATTR_CTRL_MODE,VAL_INDICATOR);
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_RED, ATTR_CTRL_MODE,VAL_INDICATOR);
	return 1;
}

//==============================================================================
// Global functions

int CVICALLBACK QUIT_GAME (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}

int CVICALLBACK GO_BACK_MAIN (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == gamePanel)
			{
				DisplayPanel (mainPanel);
			  	HidePanel (gamePanel); 
			}
			else{
				DisplayPanel (mainPanel);
			  	HidePanel (aboutPanel); 
			}
			
			   
			break;
	}
	return 0;
}

int CVICALLBACK GO_TO_ABOUT (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   DisplayPanel (aboutPanel);
			   HidePanel (mainPanel); 
			return 0;
	}
	return 0;
}

int CVICALLBACK GO_TO_GAME (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			   DisplayPanel (gamePanel);
			   HidePanel (mainPanel); 
			break;
	}
	return 0;
}

int seqNumberGanretoer (int gameLantch){
	
	int i;
	srand(time(0));
	
	 for( i = 0 ; i < gameLantch ; i++ ) 
	 {
      		///printf("%d\n", numSeqRandom[i]);
	  		numSeqRandom[i] =rand() % 4;
	 }

	return 0;
}

int roundSeqPlay(void)
   {
	   int i;
	   		  for( i = 0 ; i < levelCount*gameMode ; i++ )
			  {
				  if(numSeqRandom[i]==0)
				  {
					  
					  SetCtrlVal (gamePanel, PANEL_GAME_BTN_RED, 1);
					 
					  if (timeOut(1)==1)
					  {
						 SetCtrlVal (gamePanel, PANEL_GAME_BTN_RED, 0);
					///	 return 0;
					  }
					  
					  
					  
				  }
				   if(numSeqRandom[i]==1)
				  {
					   
					  SetCtrlVal (gamePanel, PANEL_GAME_BTN_YELLOW, 1);
					  if (timeOut(1)==1)
					  {
						SetCtrlVal (gamePanel, PANEL_GAME_BTN_YELLOW, 0); 
					///	return 0;	
					  }
					  
					  
					  
				  }
				   if(numSeqRandom[i]==2)
				  {					///	 FSOUND_PlaySound (0,green);
					   SetCtrlVal (gamePanel, PANEL_GAME_BTN_GREEN, 1);
					  if (timeOut(1)==1)
					  {
						SetCtrlVal (gamePanel, PANEL_GAME_BTN_GREEN, 0);
					///	return 0;
					  }
					  
					  
					  
				  }
				   if(numSeqRandom[i]==3)
				  {
					 /// FSOUND_PlaySound (0,blue);
					 SetCtrlVal (gamePanel, PANEL_GAME_BTN_BLUE, 1);
					  if (timeOut(1)==1)
					  {
						SetCtrlVal (gamePanel, PANEL_GAME_BTN_BLUE, 0);
					///	return 0;
					  }
					 
					  
					  
				  }
				 
				  
				 
			  }
			  
	setBtnToPlay();
	
	return 0;		  
   }


int CVICALLBACK SetGameMode (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	int val;
	switch (event)
	{
		case EVENT_COMMIT:
			   GetCtrlIndex (gamePanel, PANEL_GAME_GAME_MODE, &val);
			   ///printf("%d\n",gameMode);
			   if(val==0)
			   {  
					gameMode=1; 
					
			   }
			   if(val==1)
			   {
					gameMode=2;
			   }
			   if(val==2)
			   {
					gameMode=3;   
			   }
			   else
			   {
			   		gameMode=4; 
			   }
			  
			   
			break;
	}
	return 0;
}


int CVICALLBACK FIRE_GAME (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_START_GAME, ATTR_DIMMED, 1);
			SetCtrlAttribute (gamePanel, PANEL_GAME_GAME_MODE, ATTR_DIMMED, 1);
			setBtnToLight();
			roundSeqPlay();
	
			break;
		case EVENT_LEFT_CLICK:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}


int CVICALLBACK BTN_CHANGE (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{	
	
	if(control == PANEL_GAME_BTN_BLUE)
	{
		seqCount++;
		gameCount++;
		userInput=0;
		SetCtrlVal (gamePanel, PANEL_GAME_BTN_RED, 1);
		if (timeOut(1)==1)
		{
			SetCtrlVal (gamePanel, PANEL_GAME_BTN_RED, 0);
			return 0;
		}
	}if(control == PANEL_GAME_BTN_YELLOW)
	{
		seqCount++;
		gameCount++;
		userInput=1;
		SetCtrlVal (gamePanel, PANEL_GAME_BTN_YELLOW, 1);
		if (timeOut(1)==1)
		{
			SetCtrlVal (gamePanel, PANEL_GAME_BTN_YELLOW, 0);
			return 0;
		}	
	}if(control == PANEL_GAME_BTN_GREEN)
	{
		seqCount++;
		gameCount++;
		userInput=1;
		SetCtrlVal (gamePanel, PANEL_GAME_BTN_GREEN, 1);
		if (timeOut(1)==1)
		{
			SetCtrlVal (gamePanel, PANEL_GAME_BTN_GREEN, 0);
			return 0;
		}
	}
	else
	{
		
	}
	return 0;
}












///=========MAIN FUNCTION =======================================================
/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
	seqNumberGanretoer(gameLantheDefulet);
	/* initialize and load resources */
	
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;
	if ((mainPanel = LoadPanel (0, "Simon Gmae.uir", PANEL_MAIN)) < 0)
		return -1;
	if ((gamePanel = LoadPanel (0, "Simon Gmae.uir", PANEL_GAME)) < 0)
		return -1;
	if ((aboutPanel = LoadPanel (0, "Simon Gmae.uir", PANEL_AB)) < 0)
		return -1;
	
	/* display the panel and run the user interface */
	DisplayPanel (mainPanel);
	RunUserInterface ();
	DiscardPanel (gamePanel);
	DiscardPanel (aboutPanel);
	

}




//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void *callbackData,
		int eventData1, int eventData2)
{
	if (event == EVENT_CLOSE)
		QuitUserInterface (0);
	return 0;
}

