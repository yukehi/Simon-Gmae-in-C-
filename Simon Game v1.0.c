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
#include <windows.h>
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include <time.h>
#include <stdio.h>
#include "Simon Gmae.h"
#include "toolbox.h"
#include "bass.h" 


//==============================================================================
// variables For Functions

int printf(const char *format, ...);
int rand(void);

///// DO NOT UNDERSTED WHY SOUND DOES NOT EXCUTETS !!!!! 
HSTREAM BTN_BLUE_SND;   
HSTREAM BTN_RED_SND;   
HSTREAM BTN_GREEN_SND;
HSTREAM BTN_YELLOW_SND;
HSTREAM WRONG_SND;

void InitMP3s(void)
{
	BASS_Init( -1,44100, 0,0,NULL); 

	BTN_BLUE_SND = BASS_StreamCreateFile(FALSE,"blue.mp3",0,0,0);
    BTN_RED_SND = BASS_StreamCreateFile(FALSE,"red.mp3",0,0,0);
    BTN_GREEN_SND = BASS_StreamCreateFile(FALSE,"green.mp3",0,0,0);
    BTN_YELLOW_SND = BASS_StreamCreateFile(FALSE,"yellow.mp3",0,0,0);
    WRONG_SND = BASS_StreamCreateFile(FALSE,"wrong.mp3",0,0,0);
  
}
void ReleaseMP3s(void)
{
	 printf("%d SOUND IS ON",BASS_StreamFree(WRONG_SND));
	 BASS_StreamFree(BTN_BLUE_SND);
	 BASS_StreamFree(BTN_RED_SND);
	 BASS_StreamFree(BTN_GREEN_SND); 
	 BASS_StreamFree(BTN_YELLOW_SND);
	 BASS_StreamFree(WRONG_SND);
}

//void Chaneels (void){
//	RED_CHANNEL = BASS_SampleGetChannel(BTN_RED_SND, 0);
//	BULE_CHANNEL = BASS_SampleGetChannel(BTN_BLUE_SND, 0);
//	GREEN_CHANNEL = BASS_SampleGetChannel(BTN_GREEN_SND, 0);
//	YELLOW_CHANNEL = BASS_SampleGetChannel(BTN_YELLOW_SND, 0);
//	WRONG_CHANNEL = BASS_SampleGetChannel(WRONG_SND, 0);
//}



//==============================================================================
// global variables
int levelCount=1,gameMode=1; 
int numSeqRandom[100];
int gameCount=-1;
int seqCount=0;
int userInput=0;
int N,i; //mbintion of level and mode for ans of steps in game
int* userSeqInput;/// dynmic arry

//==============================================================================
// Static global variables

static int mainPanel = 0;
static int gamePanel = 0;
static int aboutPanel = 0;
static int scorePanel = 0;
static int gameLantheDefulet = 100;



//==============================================================================
// Static functions
int LoopThrowArry (int arry[]){
	int loop;
	for(loop = 0; loop <N; loop++)
		{
     	printf("\n %d user \n", arry[loop]);
	  			
		}
	return 0;
}

int LoopThrowArryCOM (int arry[]){
	int loop;
	for(loop = 0; loop <N; loop++)
		{
     	printf("\n %d com \n", arry[loop]);
	  			
		}
	return 0;
}

int timeOut( double seconds )
{
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC ;
    while (clock() < endwait) {}

    return  1;
}

int setBtnToPlay(void)
{
	userSeqInput=(int*)calloc(N,N* sizeof(int));
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


int checkSeq (int userSeq[], int comSeq[], int Size) {
    
	for(i=0;i<Size;i++)
	{
	
		printf("\n user sequnse = %d",userSeq[i]);
		printf("\n com sequnse  = %d",comSeq[i]);
		if(userSeq[i] != comSeq[i])
		{
			/// ACTIVETING THE AGIEN BTN
			gameCount=-1;
			levelCount=1;
			SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_AGIAN, ATTR_DIMMED, 0);
			SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_NEXT_LEVEL, ATTR_DIMMED, 1);
			SetCtrlVal (gamePanel, PANEL_GAME_levelCountr,levelCount);
			//printf("\n SHIT HAPPEN!!!!!! userinput = %d",userInput);
			break;	
			}
	/// ACTIVETING THE NEXT LEVEL BTN
		else{
		gameCount=-1;
		SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_NEXT_LEVEL, ATTR_DIMMED, 0);
		//printf("\n YOU DID RIGHT MY SON  %d",userInput);	
		
		}
	}
	return 1;
}

int gameLenth (int level, int mode) {
	N = level*mode;
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
	   		  for( i = 0 ; i < levelCount*gameMode ; i++ )
			  {
				  if(numSeqRandom[i]==0)
				  {
					   if (timeOut(0.5)==1)
					  {
					  SetCtrlVal (gamePanel, PANEL_GAME_LED_RED, 1);
					  BASS_ChannelPlay(BTN_RED_SND,TRUE);
					  
					  }
					  if (timeOut(0.5)==1)
					  {
						 SetCtrlVal (gamePanel, PANEL_GAME_LED_RED, 0);
					  }
				  }
				   if(numSeqRandom[i]==1)
				  {
					   if (timeOut(0.5)==1)
					  {
					  SetCtrlVal (gamePanel, PANEL_GAME_LED_YELLOW, 1);
					  BASS_ChannelPlay(BTN_YELLOW_SND,TRUE);
					  }
					  if (timeOut(0.5)==1)
					  {
						SetCtrlVal (gamePanel, PANEL_GAME_LED_YELLOW, 0); 
					  }
				  }
				   if(numSeqRandom[i]==2)
				  {		
					   if (timeOut(0.5)==1)
					  {
					   SetCtrlVal (gamePanel, PANEL_GAME_LED_GREEN, 1);
					   BASS_ChannelPlay(BTN_GREEN_SND,TRUE);
					  }
					  if (timeOut(0.5)==1)
					  {
						SetCtrlVal (gamePanel, PANEL_GAME_LED_GREEN, 0);
					  }  
				  }
				   if(numSeqRandom[i]==3)
				  {
					  if (timeOut(0.5)==1)
					  {
					 SetCtrlVal (gamePanel, PANEL_GAME_LED_BLUE, 1);
					 BASS_ChannelPlay(BTN_BLUE_SND,TRUE);
					  }
					  if (timeOut(0.5)==1)
					  {
						SetCtrlVal (gamePanel, PANEL_GAME_LED_BLUE, 0);
					  }
				  }
			  }
	gameLenth(levelCount,gameMode);
	setBtnToPlay();
	return 0;		  
   }





///=========MAIN FUNCTION =======================================================
/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
			/// MOST EXCUTE TO CRATE FIRST MEMORY SLOT
		seqNumberGanretoer(gameLantheDefulet);
		userSeqInput=(int*)calloc(gameLantheDefulet ,gameLantheDefulet * sizeof(int) ); //
		/* initialize and load resources */
		if (InitCVIRTE (0, argv, 0) == 0)
			return -1;
		if ((mainPanel = LoadPanel (0, "Simon Gmae.uir", PANEL_MAIN)) < 0)
			return -1;
		if ((gamePanel = LoadPanel (0, "Simon Gmae.uir", PANEL_GAME)) < 0)
			return -1;
		if ((aboutPanel = LoadPanel (0, "Simon Gmae.uir", PANEL_AB)) < 0)
			return -1;
		if ((scorePanel = LoadPanel (0, "Simon Gmae.uir", PANELSCORE)) < 0)
			return -1;
		
		/* display the panel and run the user interface */
		InitMP3s();
		ReleaseMP3s();
		DisplayPanel (mainPanel);
		RunUserInterface ();
		DiscardPanel (gamePanel);
		DiscardPanel (aboutPanel);
		DiscardPanel (scorePanel);
		

	

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


int CVICALLBACK SetGameMode (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	int val;
	switch (event)
	{
		case EVENT_COMMIT:
			
			   GetCtrlIndex (gamePanel, PANEL_GAME_GAME_MODE, &val);
			   ///printf("%d\n",gameMode);
			   
			   if(val==1)
			   {  
					gameMode=1; 
					
			   }
			   if(val==2)
			   {
					gameMode=2;
			   }
			   if(val==3)
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
			SetCtrlVal (gamePanel, PANEL_GAME_levelCountr, levelCount);/// does not switch the number
			SetCtrlIndex (gamePanel, PANEL_GAME_GAME_MODE, 0);
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
	
	switch (event)
	{
			case EVENT_COMMIT:
				switch (control)
				{
					case PANEL_GAME_BTN_RED:
							seqCount++;
							gameCount++;
							userInput=0;
							if (timeOut(0.5)==1)
							{
							SetCtrlVal (gamePanel, PANEL_GAME_LED_RED, 1);
							BASS_ChannelPlay(BTN_RED_SND,TRUE);

							}
							if (timeOut(0.5)==1)
							{
								SetCtrlVal (gamePanel, PANEL_GAME_LED_RED, 0);
								break;
							}
							
					
					case PANEL_GAME_BTN_YELLOW:
							seqCount++;
							gameCount++;
							userInput=1;
							if (timeOut(0.5)==1)
							{
							SetCtrlVal (gamePanel, PANEL_GAME_LED_YELLOW, 1);
							BASS_ChannelPlay(BTN_YELLOW_SND,TRUE);
							}
							if (timeOut(0.5)==1)
							{
								SetCtrlVal (gamePanel, PANEL_GAME_LED_YELLOW,0);
								break;
							}	
							
					
					case PANEL_GAME_BTN_GREEN:
							seqCount++;
							gameCount++;
							userInput=2;
							if (timeOut(0.5)==1)
							{
							SetCtrlVal (gamePanel, PANEL_GAME_LED_GREEN, 1);
							BASS_ChannelPlay(BTN_GREEN_SND,TRUE);

							}
							if (timeOut(0.5)==1)
							{
								SetCtrlVal (gamePanel, PANEL_GAME_LED_GREEN, 0);
								break;
								
							}
							
					
					case PANEL_GAME_BTN_BLUE:
							seqCount++;
							gameCount++;
							userInput=3;
							if (timeOut(0.5)==1)
							{
							SetCtrlVal (gamePanel, PANEL_GAME_LED_BLUE, 1);
							BASS_ChannelPlay(BTN_BLUE_SND,TRUE);

							}
							if (timeOut(0.5)==1)
							{
								SetCtrlVal (gamePanel, PANEL_GAME_LED_BLUE, 0);
								break;
							}
				}
				userSeqInput[gameCount]=userInput;
				if(seqCount == N)
				{
					//printf("\n WE START THE CHECK  last user input \n %d",userInput);
					checkSeq(userSeqInput,numSeqRandom,N);
				}
	break;	
	}
	return 0;
}


int CVICALLBACK nextLevel (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			LoopThrowArry(userSeqInput);
			LoopThrowArryCOM(numSeqRandom);
			free(userSeqInput);
			levelCount++;
			userSeqInput=(int*)calloc(N,N * sizeof(int));
			SetCtrlVal (gamePanel, PANEL_GAME_levelCountr, levelCount);
			seqCount=0;
			setBtnToLight();
			roundSeqPlay();
			SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_NEXT_LEVEL, ATTR_DIMMED, 1);
			break;
	}
	
	return 0;
}

int CVICALLBACK TryAgian (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			free(userSeqInput);
			userSeqInput=(int*)calloc(N,N * sizeof(int));
			gameCount=-1;
			seqNumberGanretoer(N);
			seqCount=0;
			setBtnToLight();
			roundSeqPlay();
			SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_AGIAN, ATTR_DIMMED, 1);
			break;
			
			///does not change back the level on plaen 

	}
	return 0;
}

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

int CVICALLBACK GO_SCORE (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			   DisplayPanel (scorePanel);
			   HidePanel (gamePanel); 
			break;
	}
	return 0;
}





int CVICALLBACK TIMER (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			/*int x;
			GetCtrlVal (gamePanel, PANEL_GAME_LED_GREEN, &x);
			if(x == 1){
			BASS_ChannelPlay(BTN_GREEN_SND,TRUE);
			}*/
			break;
	}
	return 0;
}
