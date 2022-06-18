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

#define  PANEL_GAME                       2
#define  PANEL_GAME_LED_GREEN             2       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_LED_BLUE              3       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_LED_YELLOW            4       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_LED_RED               5       /* control type: LED, callback function: (none) */
#define  PANEL_GAME_BTN_QUIT              6       /* control type: command, callback function: QUIT_GAME */
#define  PANEL_GAME_BTN_NEXT_LEVEL        7       /* control type: command, callback function: nextLevel */
#define  PANEL_GAME_BTN_BACK              8       /* control type: command, callback function: GO_BACK_MAIN */
#define  PANEL_GAME_BTN_AGIAN             9       /* control type: command, callback function: TryAgian */
#define  PANEL_GAME_BTN_START_GAME        10      /* control type: command, callback function: FIRE_GAME */
#define  PANEL_GAME_GAME_MODE             11      /* control type: slide, callback function: SetGameMode */
#define  PANEL_GAME_BTN_GREEN             12      /* control type: toggle, callback function: BTN_CHANGE */
#define  PANEL_GAME_BTN_BLUE              13      /* control type: toggle, callback function: BTN_CHANGE */
#define  PANEL_GAME_BTN_YELLOW            14      /* control type: toggle, callback function: BTN_CHANGE */
#define  PANEL_GAME_BTN_RED               15      /* control type: toggle, callback function: BTN_CHANGE */

#define  PANEL_MAIN                       3       /* callback function: panelCB */
#define  PANEL_MAIN_BTN_QUIT              2       /* control type: command, callback function: QUIT_GAME */
#define  PANEL_MAIN_BTN_ABOUT_MANUE       3       /* control type: command, callback function: GO_TO_ABOUT */
#define  PANEL_MAIN_BTN_GAME_MODE_MANUE   4       /* control type: command, callback function: GO_TO_GAME */
#define  PANEL_MAIN_SIMON_GMAE_LOGO       5       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK BTN_CHANGE(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK FIRE_GAME(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_BACK_MAIN(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_TO_ABOUT(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK GO_TO_GAME(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK nextLevel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QUIT_GAME(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SetGameMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TryAgian(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif