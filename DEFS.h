#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	ITM_SELECT1, // Select figure item in menu
	ITM_CHANGECOLOR1, //Change color of drawing item in menu
	ITM_CHANGEFILLINGS1, //Change fillimgs color in menu
	ITM_RECT1,		//Recangle item in menu
	ITM_SQUARE1, // Square item in menu
	ITM_TRI1,  // Triangle item in menu
	ITM_HEX1, // Hexagin item in menu
	ITM_CIRCLE1, // Circle item in menu
	ITM_BLACK1, // Black color in menu
	ITM_YELLOW1, // Yellow color in menu
	ITM_ORANGE1, // Orange color in menu
	ITM_RED1, // Red color in menu
	ITM_GREEN1, // Green color in menu
	ITM_BLUE1, // Blue color in menu
	ITM_DELETE1, // Delete figure item in menu
	ITM_MOVE1, //Move figure item in menu
	ITM_RESIZE1,
	ITM_DRAG1,
	ITM_UNDO1, // Undo item in menu
	ITM_REDO1, // Redo item in menu
	ITM_MUTE1,
	ITM_CLEARALL1, // Clear all item in menu
	ITM_REC1, // Recording item in menu
	ITM_STOPREC1, // Stop recording item in menu
	ITM_PLAY1, // Play recording itemin menu
	ITM_SAVE1, //Save graph item in menu
	ITM_LOAD1, // Load graph item in menu
	TO_PLAY,
	ITM_EXIT1,		//Exit item
	ITM_DRAWMODE1, // Switch to draw mode 
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	FIGURETYPE, //Plays figure type item in menu
	FIGURECOLOR, //Plays figure color item in menu
	FIGTYPEANDCOLOR, //Plays figure type and color item in menu
	RESTART,//restart
	TO_DRAW,

	EXIT


	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif