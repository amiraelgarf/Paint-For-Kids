#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
		{
			return Label;
			break;
		}
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return ITM_RECT1;
			case ITM_EXIT: return EXIT;
			case ITM_SELECT: return ITM_SELECT1;
			case ITM_CHANGECOLOR:return ITM_CHANGECOLOR1;
			case ITM_CHANGEFILLINGS: return ITM_CHANGEFILLINGS1;
			case ITM_SQUARE: return ITM_SQUARE1;
			case ITM_TRI: return ITM_TRI1;
			case ITM_HEX: return ITM_HEX1;
			case ITM_CIRCLE: return ITM_CIRCLE1;
			case ITM_BLACK: return ITM_BLACK1;
			case ITM_YELLOW: return ITM_YELLOW1;
			case ITM_ORANGE:return ITM_ORANGE1;
			case ITM_RED: return ITM_RED1;
			case ITM_GREEN: return ITM_GREEN1;
			case ITM_BLUE: return ITM_BLUE1;
			case ITM_DELETE: return ITM_DELETE1;
			case ITM_MOVE: return ITM_MOVE1;
			case ITM_RESIZE:return ITM_RESIZE1;
			case ITM_DRAG: return ITM_DRAG1;
			case ITM_UNDO: return ITM_UNDO1;
			case ITM_REDO: return ITM_REDO1;
			case ITM_MUTE:return ITM_MUTE1;
			case ITM_CLEARALL: return ITM_CLEARALL1;
			case ITM_REC: return ITM_REC1;
			case ITM_STOPREC: return ITM_STOPREC1;
			case ITM_PLAY: return ITM_PLAY1;
			case ITM_SAVE:return ITM_SAVE1;
			case ITM_LOAD:return ITM_LOAD1;
			case ITM_PLAYMODE:  return TO_PLAY;




			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_FIGURETYPE: return FIGURETYPE;
			case ITM_FIGURECOLOR: return FIGURECOLOR;
			case ITM_FIGTYPEANDCOLOR: return FIGTYPEANDCOLOR;
			case ITM_DRAW: return TO_DRAW;
			case ITM_RESTART: return RESTART;
			case EXIT1: return EXIT;






			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}
/////////////////////////////////

void Input::GetMouseCrdnts(int& x, int& y) const
{
	pWind->GetMouseCoord(x, y);
}
bool Input::MouseClick(int& x, int& y)
{
	if (pWind->GetMouseClick(x, y) == NO_CLICK)
		return false;
	else
		return true;
}

Input::~Input()
{
}
