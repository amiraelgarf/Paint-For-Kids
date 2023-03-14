#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_SELECT, // Select figure item in menu
	ITM_CHANGECOLOR, //Change color of drawing item in menu
	ITM_CHANGEFILLINGS, //Change fillimgs color in menu
	ITM_RECT,		//Recangle item in menu
	ITM_SQUARE, // Square item in menu
	ITM_TRI,  // Triangle item in menu
	ITM_HEX, // Hexagin item in menu
	ITM_CIRCLE, // Circle item in menu
	ITM_BLACK, // Black color in menu
	ITM_YELLOW, // Yellow color in menu
	ITM_ORANGE, // Orange color in menu
	ITM_RED, // Red color in menu
	ITM_GREEN, // Green color in menu
	ITM_BLUE, // Blue color in menu
	ITM_DELETE, // Delete figure item in menu
	ITM_MOVE, //Move figure item in menu
	ITM_RESIZE,
	ITM_DRAG,
	ITM_UNDO, // Undo item in menu
	ITM_REDO, // Redo item in menu
	ITM_MUTE,
	ITM_CLEARALL, // Clear all item in menu
	ITM_REC, // Recording item in menu
	ITM_STOPREC, // Stop recording item in menu
	ITM_PLAY, // Play recording itemin menu
	ITM_SAVE, //Save graph item in menu
	ITM_LOAD, // Load graph item in menu
	ITM_PLAYMODE, // Play mode item in menu
	ITM_EXIT,		//Exit item
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	ITM_FIGURETYPE, //Plays figure type item in menu
	ITM_FIGURECOLOR, //Plays figure color item in menu
	ITM_FIGTYPEANDCOLOR, //Plays figure type and color item in menu
	ITM_DRAW, //Draw mode item in menu
	ITM_RESTART, //restart 
	EXIT1,		//Exit item
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};


__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool DEFFILL; //THE DFAULT FILL
	/// Add more members if needed

}UI;	//create a global object UI

#endif