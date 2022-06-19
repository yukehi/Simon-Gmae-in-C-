/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL_AB                         1
#define  PANEL_AB_BTN_BACK                2       /* control type: command, callback function: GO_BACK_MAIN */
#define  PANEL_AB_BTN_QUIT                3       /* control type: command, callback function: (none) */
#define  PANEL_AB_ABOUTCONTACT            4       /* control type: picture, callback function: (none) */

#define  PANEL_GAME                       2
#define  PANEL_GAME_LED_GREEN             2       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_LED_BLUE              3       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_LED_YELLOW            4       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_BTN_AGIAN             5       /* control type: command, callback function: TryAgian */
#define  PANEL_GAME_LED_RED               6       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_BTN_QUIT              7       /* control type: command, callback function: QUIT_GAME */
#define  PANEL_GAME_BTN_NEXT_LEVEL        8       /* control type: command, callback function: nextLevel */
#define  PANEL_GAME_BTN_SCORE             9       /* control type: command, callback function: GO_SCORE */
#define  PANEL_GAME_BTN_START_GAME        10      /* control type: command, callback function: FIRE_GAME */
#define  PANEL_GAME_BTN_GREEN             11      /* control type: toggle, callback function: BTN_CHANGE */
#define  PANEL_GAME_BTN_BLUE              12      /* control type: toggle, callback function: BTN_CHANGE */
#define  PANEL_GAME_BTN_YELLOW            13      /* control type: toggle, callback function: BTN_CHANGE */
#define  PANEL_GAME_BTN_RED               14      /* control type: toggle, callback function: BTN_CHANGE */
#define  PANEL_GAME_levelHeadLine         15      /* control type: textMsg, callback function: (none) */
#define  PANEL_GAME_levelCountr           16      /* control type: numeric, callback function: (none) */

#define  PANEL_INPU                       3
#define  PANEL_INPU_NAME                  2       /* control type: string, callback function: (none) */
#define  PANEL_INPU_BTN_SUBMIT            3       /* control type: command, callback function: SUBMIT_SCORE */
#define  PANEL_INPU_BTN_SET_GAME          4       /* control type: command, callback function: GO_PANEL_SET */
#define  PANEL_INPU_BTN_AGIAN             5       /* control type: command, callback function: TryAgian */

#define  PANEL_MAIN                       4       /* callback function: panelCB */
#define  PANEL_MAIN_BTN_QUIT              2       /* control type: command, callback function: QUIT_GAME */
#define  PANEL_MAIN_BTN_ABOUT_MANUE       3       /* control type: command, callback function: GO_TO_ABOUT */
#define  PANEL_MAIN_BTN_GAME_MODE_MANUE   4       /* control type: command, callback function: GO_TO_SET */
#define  PANEL_MAIN_SIMON_GMAE_LOGO       5       /* control type: picture, callback function: (none) */

#define  PANEL_SET                        5
#define  PANEL_SET_GAME_MODE_TIME         2       /* control type: slide, callback function: SetGameModeTime */
#define  PANEL_SET_GAME_MODE              3       /* control type: slide, callback function: SetGameMode */
#define  PANEL_SET_BTN_GO_PLAY_PANEL      4       /* control type: command, callback function: GO_TO_GAME */
#define  PANEL_SET_BTN_BACK               5       /* control type: command, callback function: GO_BACK_MAIN */

#define  PANELSCORE                       6
#define  PANELSCORE_SCORE_THIRD           2       /* control type: numeric, callback function: (none) */
#define  PANELSCORE_SCORE_SECAND          3       /* control type: numeric, callback function: (none) */
#define  PANELSCORE_SCORE_FOURTH          4       /* control type: numeric, callback function: (none) */
#define  PANELSCORE_SCORE_FIRST           5       /* control type: numeric, callback function: (none) */
#define  PANELSCORE_H1_TABLE_2            6       /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_BTN_BACK              7       /* control type: command, callback function: GO_TO_GAME */
#define  PANELSCORE_H1_TABLE_3            8       /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_H1_TABLE_4            9       /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_H1_TABLE_5            10      /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_H1_TABLE              11      /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_H1_THIRD_NAME         12      /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_H1_FOURTH_NAME        13      /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_H1_SECAND_NAME        14      /* control type: textMsg, callback function: (none) */
#define  PANELSCORE_H1_FIRST_NAME         15      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK BTN_CHANGE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK FIRE_GAME(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_BACK_MAIN(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_PANEL_SET(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_SCORE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_TO_ABOUT(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_TO_GAME(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_TO_SET(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK nextLevel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QUIT_GAME(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SetGameMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SetGameModeTime(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SUBMIT_SCORE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TryAgian(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif