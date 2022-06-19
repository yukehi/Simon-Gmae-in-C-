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
#include <playsoundapi.h>



//==============================================================================
//  For Functions

int printf(const char *format, ...);
int rand(void);

struct newScoreBored
{
   int a[4];
};

struct newScoreBored bored;




//==============================================================================
// global variables
int levelCount=1,gameMode=1; 
int numSeqRandom[100];
int gameCount=-1;
int seqCount=0;
int userInput=0;
int N,i;//mbintion of level and mode for ans of steps in game
double p;
int* userSeqInput;/// dynmic arry
int gameTime = 25;
//==============================================================================
// Static global variables

static int mainPanel = 0;
static int gamePanel = 0;
static int aboutPanel = 0;
static int scorePanel = 0;
static int inputPanel = 0;
static int modePanel = 0;




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

int playBtn (int btn){
	switch (btn)
	{
		case 0:
			PlaySound(TEXT("X:\\Simon Game V.1.1\\Audio\\red.wav"), NULL,SND_FILENAME | SND_ASYNC);
			break;
		case 1:
			PlaySound(TEXT("X:\\Simon Game V.1.1\\Audio\\blue.wav"), NULL,SND_FILENAME | SND_ASYNC);
			break;
		case 2:
			PlaySound(TEXT("X:\\Simon Game V.1.1\\Audio\\green.wav"), NULL,SND_FILENAME | SND_ASYNC);
			break;
		case 3:
			PlaySound(TEXT("X:\\Simon Game V.1.1\\Audio\\yellow.wav"),NULL,SND_FILENAME | SND_ASYNC);
			break;	
		case 4:
			PlaySound(TEXT("X:\\Simon Game V.1.1\\Audio\\wrong.wav"), NULL,SND_FILENAME | SND_ASYNC);
			break;	
		case 5:
			PlaySound(TEXT("X:\\Simon Game V.1.1\\Audio\\next.wav"), NULL,SND_FILENAME | SND_ASYNC);
			break;		
	}
	return 0;
}

int checkScoreBorad (){
	

	return 0;
}



//==============================================================================
// Global functions


int checkSeq (int userSeq[], int comSeq[], int Size) {
    
	for(i=0;i<Size;i++)
	{
		if(userSeq[i] != comSeq[i])
		{
			/// ACTIVETING THE AGIEN BTN
			playBtn(4);
			gameCount=-1;
			levelCount=1;
			setBtnToLight();
			SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_NEXT_LEVEL, ATTR_VISIBLE, 1);
			SetCtrlVal (gamePanel, PANEL_GAME_levelCountr,levelCount);
			if( p > bored.a[0] && p < bored.a[3]){
				DisplayPanel (inputPanel);
				HidePanel (gamePanel);
			}else{
				SetCtrlAttribute (inputPanel, PANEL_INPU_BTN_AGIAN, ATTR_VISIBLE , 0);
			}
			
			//check score borad 
			break;	
			}
	/// ACTIVETING THE NEXT LEVEL BTN
		else{
		playBtn(5);
		setBtnToLight();
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
					  playBtn(0);
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
					  playBtn(3);
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
					   playBtn(2);
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
					 playBtn(1);
					  }
					  if (timeOut(0.5)==1)
					  {
						SetCtrlVal (gamePanel, PANEL_GAME_LED_BLUE, 0);
					  }
				  }
			  }
	setBtnToPlay();
	return 0;		  
   }

int instalizeGame(){
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_START_GAME, ATTR_DIMMED, 1);
	//SetCtrlAttribute (gamePanel, PANEL_SET_GAME_MODE, ATTR_DIMMED, 1);
	SetCtrlVal (gamePanel, PANEL_GAME_levelCountr, levelCount);/// does not switch the number
	//SetCtrlIndex (gamePanel, PANEL_SET_GAME_MODE, 0);
	setBtnToLight();
	roundSeqPlay();
	

	return 0;
}

int setSameGame(){
	free(userSeqInput);
	userSeqInput=(int*)calloc(N,N * sizeof(int));
	gameCount=-1;
	seqNumberGanretoer(N);
	seqCount=0;
	setBtnToLight();
	roundSeqPlay();

	return 0;
}

int setNextLevel(){
	//LoopThrowArry(userSeqInput);
	//LoopThrowArryCOM(numSeqRandom);
	SetCtrlAttribute (gamePanel, PANEL_GAME_BTN_NEXT_LEVEL, ATTR_DIMMED, 1);
	free(userSeqInput);
	levelCount++;
	userSeqInput=(int*)calloc(N,N * sizeof(int));
	SetCtrlVal (gamePanel, PANEL_GAME_levelCountr, levelCount);
	seqCount=0;
	setBtnToLight();
	roundSeqPlay();
	return 0;
}

int BtnOnInSet(){
	SetCtrlAttribute (gamePanel, PANEL_INPU_BTN_AGIAN, ATTR_DIMMED, 1);
	SetCtrlAttribute (gamePanel, PANEL_INPU_BTN_SET_GAME, ATTR_DIMMED, 1);
	return 0;
}
int pushScoreToBorad(){
	///CANT GET THE CHERCTER VALUE NEEDED TO BE CHEKED 
	int val;
	GetCtrlAttribute (gamePanel, PANEL_INPU_NAME, ATTR_DFLT_VALUE, &val);
	int len = sizeof(val);
	printf("%d", len);
	if( len == NULL){
		MessageBox( 0, TEXT( "You Most Put A Name between 1-10 "), TEXT( "ERROER" ), MB_OK );
		return 1;
	}if(len > 1 && len < 10){
		if( p > bored.a[0] && p < bored.a[1]){
			SetCtrlVal (scorePanel, PANELSCORE_SCORE_FIRST,N);
			SetCtrlVal (scorePanel, PANELSCORE_H1_FIRST_NAME,val);
			BtnOnInSet();
		}if( p > bored.a[1] && p > bored.a[2]){
			SetCtrlVal (scorePanel, PANELSCORE_SCORE_SECAND,N);
			SetCtrlVal (scorePanel, PANELSCORE_H1_SECAND_NAME, val);
			BtnOnInSet();
		}if( p > bored.a[2] && p > bored.a[3]){
			SetCtrlVal (scorePanel, PANELSCORE_SCORE_THIRD,N);
			SetCtrlVal (scorePanel, PANELSCORE_H1_THIRD_NAME, val);
			BtnOnInSet();
		}else{
			SetCtrlVal (scorePanel, PANELSCORE_SCORE_FOURTH,N);
			SetCtrlVal (scorePanel, PANELSCORE_H1_FOURTH_NAME ,val);
			BtnOnInSet();
	}	
	
	}if(len < 10){
		MessageBox( 0, TEXT( "You Most Put A Name between 1-10 "), TEXT( "ERROER" ), MB_OK );
		return 1;
	}
	
	return 0;
}

int setScoreRuls(){
	for (i=0; i<4; i++)
	{
		float percentage;
		percentage = (100 * 100.0) / N * i;
		//printf("\n  bored Percentage = %.2f%%", percentage);
		bored.a[i] = percentage;
	}
	
	
	return  0;
};

int setGameTime(){
		seqNumberGanretoer(gameTime);
		userSeqInput=(int*)calloc(gameTime ,gameTime * sizeof(int) );
		gameLenth(levelCount,gameMode);
		p = (N * 100.0) ;
		setScoreRuls();
		return 0;
}


///=========MAIN FUNCTION =======================================================
/// HIFN The main entry-point function.
int main (int argc, char *argv[])
{
		
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
		if ((inputPanel = LoadPanel (0, "Simon Gmae.uir", PANEL_INPU)) < 0)
			return -1;
		if ((modePanel = LoadPanel (0, "Simon Gmae.uir", PANEL_SET)) < 0)
			return -1;
		
		
		
		/* display the panel and run the user interface */
		DisplayPanel (mainPanel);
		RunUserInterface ();
		DiscardPanel (gamePanel);
		DiscardPanel (modePanel);
		DiscardPanel (aboutPanel);
		DiscardPanel (inputPanel);
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
			
			   GetCtrlIndex (modePanel, PANEL_SET_GAME_MODE, &val);
			   ///printf("%d\n",gameMode);
			   switch (val)
			   {
			   	case 2:
			   		gameMode=2;
			   		break;
			   	case 3:
					gameMode=3;
			   		break;
				case 4:
					gameMode=4; 
			   		break;
			   	default:
					gameMode=1; 
			   		break;
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
			instalizeGame();
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
							playBtn(0);

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
							playBtn(3);
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
							playBtn(2);

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
							playBtn(1);
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

///PREOBLEM!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int CVICALLBACK nextLevel (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			setNextLevel();
			//problem with memoery 
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
			setSameGame();
			break;

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
			if(panel == modePanel)
			{
				DisplayPanel (mainPanel);
			  	HidePanel (modePanel); 
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
			setGameTime();
			DisplayPanel (gamePanel);
			HidePanel (modePanel); 
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



int CVICALLBACK GO_BACK_SET_PANEL (int panel, int control, int event,
								   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			instalizeGame();
			DisplayPanel (modePanel);
			HidePanel (gamePanel); 
			break;
	}
	return 0;
}

int CVICALLBACK SUBMIT_SCORE (int panel, int control, int event,
							void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			pushScoreToBorad();
			break;
	}
	return 0;
}

int CVICALLBACK GO_PANEL_SET (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (modePanel);
			HidePanel (inputPanel);
			break;
	}
	return 0;
}

int CVICALLBACK SetGameModeTime (int panel, int control, int event,
								 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int index;
			GetCtrlIndex (modePanel, PANEL_SET_GAME_MODE_TIME, &index);
			   switch (index)
				  
			   {
			   	case 1:
					gameTime = 35;
			   		break;
			   	case 2:
					gameTime = 50;
			   		break;
				case 3:
					gameTime = 100;
			   		break;
			   	case 0:
					gameTime = 25; 
			   		break;
			  	}
			break;
	}
	return 0;
}

int CVICALLBACK GO_TO_SET (int panel, int control, int event,
						   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			DisplayPanel (modePanel);
			HidePanel (mainPanel); 
			break;
	}
	return 0;
}
