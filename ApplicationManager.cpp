#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Add_sqaure_action.h"
#include "add_circle_action.h"
#include "Addtriangleaction.h"
#include "Addhexagon.h"
#include "Delete.h"
#include "Move.h"
#include "Select.h"
#include "Startrec.h"
#include "Resize.h"
#include "GUI/Input.h"
#include "Saveaction.h"
#include "LoadAction.h"
#include "SwitchToPlayMode.h"
#include "PlayRecordingAction.h"
#include "ClearAll.h"
#include "ExitAction.h"
#include "PickByFig.h"
#include "PickByClr.h"
#include "PickByBoth.h"
#include "Pick_Hide.h"
#include "Restart.h"
#include "ToDraw.h"
#include <Windows.h>
#include "MoveDrag.h"
#include "MMSystem.h"
#include "Sound.h"
#include "FillColour.h"
#include "Undo.h"
#include "Redo.h"
#include "Red.h"
#include "DrawColor.h"
#include "Black.h"
#include "Blue.h"
#include "Orange.h"
#include "Yellow.h"
#include "Green.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	Actioncount = 0;
	undocount = 0;
	mute_not = 1;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	//Create an array of actions pointers and set them to NULL		
	for (int i = 0; i < 20; i++)
		Recordactions[i] = NULL;
	Lastaction = NULL;
	record = false;
	moveindex1 = 700;
	moveindex2 = 700;
	for (int i = 0; i < 2; i++)
	{
		movefig[i] = NULL;
	}
	movefigcount = 0;
	movecheck1 = false;
	movecheck2 = false;

	for (int i = 0; i < 5; i++)
	{
		UndoList[i] = NULL;
	}
	Filled = false;
	Draw = false;
	lastactionindex = 0;
	LastFigCount = 0;
	undomax = false;


}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	int x1 = 0, y1 = 0;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case ITM_RECT:
			pAct = new AddRectAction(this);
			break;

		case ITM_SQUARE:
			pAct = new Add_sqaure_action(this);
			break;

		case ITM_CIRCLE:
			pAct = new add_circle_action(this);
			break;

		case ITM_TRI:
			pAct = new Addtriangleaction(this);
			break;

		case ITM_HEX:
			pAct = new Addhexagon(this);
			break;

		case ITM_SELECT:
			pAct = new Select(this);
			break;
	
		case ITM_REC:
			pAct = new StartRec(this);
			break; 

		case ITM_STOPREC:
			setrecord(false); 
			pOut->PrintMessage("rec stopped");
			break;

		case ITM_PLAY:
			pAct = new PlayRecordingAction(this);
			break;

		case ITM_DELETE1:
			pAct = new Delete(this);
			break;

		case ITM_MOVE1:
			pAct = new Move(this);
			break;
		case ITM_SAVE:
			pAct = new Saveaction(this);
			break;
		
		case ITM_LOAD:
			pAct = new LoadAction(this);
			break;

		case ITM_RESIZE:
			pAct = new Resize(this);
			break;

		case ITM_MUTE:
			pAct = new sound(this);
			break;

		case ITM_DRAG:
			pAct = new MoveDrag(this);
			break;

		case ITM_PLAYMODE:
			pAct= new SwitchToPlayMode(this);
			break;

		case ITM_CLEARALL:
			pAct= new ClearAll(this);
			break;

		case EXIT:
			pAct= new ExitAction(this);

			break;
		case FIGURETYPE:
			pAct = new pickfig(this);
			break;

		case FIGURECOLOR:
			pAct = new pickclr(this);
			break;

		case FIGTYPEANDCOLOR:
			pAct = new pickboth(this);
			break;

		case RESTART:
			pAct = new restart(this);
			break;

		case TO_DRAW:
			pAct = new toDraw(this);
			break;

		case ITM_UNDO1:
			pAct = new Undo(this);
			break;

		case ITM_REDO1:
			pAct = new Redo(this);
			break;

		case ITM_CHANGEFILLINGS1:
			pAct = new FillColour(this);
			break;

		case ITM_RED1:
			pAct = new Red(this);
			break;

		case ITM_CHANGECOLOR1:
			pAct = new DrawColor(this);
			break;

		case ITM_BLACK1:
			pAct = new Black(this);
			break;

		case ITM_BLUE1:
			pAct = new Blue(this);
			break;

		case ITM_ORANGE1:
			pAct = new Orange(this);
			break;

		case ITM_YELLOW1:
			pAct = new Yellow(this);
			break;

		case ITM_GREEN1:
			pAct = new Green(this);
			break;

		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		Lastaction = pAct;
		pAct = NULL;
	}
}
//==================================================================================//
//                           Added Functions                         //
// =================================================================================//
// get whether current state is mute or sound on

bool ApplicationManager::getSoundState()
{
	return mute_not;
}
void ApplicationManager::setSoundState(bool s)
{
	mute_not = s;
}
void ApplicationManager::switchSoundState()
{
	bool s = mute_not;
	mute_not = !s;
}
// // get random shape to be the criteria in pick and hide
CFigure* ApplicationManager::GetRandomFigure()
{
	srand(0);
	if (FigCount > 0)
	{
		int i = rand() % FigCount;
		return FigList[i];
	}
	else
		return NULL;
}
//CFigure* ApplicationManager::getFigList(int index)
//{
//	return FigList[index];
//}
////  // get fig count
//int ApplicationManager::getFigCount()
//{
//	return FigCount;
//}
////    // deleting a figure
void ApplicationManager::DeleteFigPlay(CFigure* C)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (C == FigList[i])
		{ 
			FigList[i] = NULL;                                //deleting a figure
			FigList[i] = FigList[FigCount - 1];               //replacing empty space with the last figure in the list
			FigList[FigCount - 1] = NULL;                     //freeing the last space
		FigCount--;                                       // reducing count
	}
	}
}
//bool ApplicationManager::sameclr(CFigure* C, CFigure* F)
//{
//	if (C->getColor() == F->getColor())
//		return true;
//	else
//		return false;
//}
//bool ApplicationManager::sameType(CFigure* C, CFigure* F)
//{
//	PickHide* ph1 ;
//	PickHide* ph2 ;
//	if (ph1->getFigType(C) == ph2->getFigType(F))
//		return true;
//	else
//		return false;
//}
int ApplicationManager::getCorrectCount(CFigure* C, char criteria)
{
	PickHide* ph = NULL;
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if ((criteria == 'c') && ph->sameclr(C, FigList[i]))               //criteria is colour of CFigure C
			count++;
		else if ((criteria == 't') && ph->sameType(C, FigList[i]))            //criteria is type of CFigure C
			count++;
		else if ((criteria == 'b') && ph->sameclr(C, FigList[i]) && ph->sameType(C, FigList[i]))      //criteria is both type and colour
			count++;
	}
	return count;
}
////////////////////////////////////////////////////////////////////////////////////
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y, bool& unselect) const
{
	for (int i = FigCount; i >= 0; i--)
	{
		if (FigList[i] != NULL)
		{
			unselect = FigList[i]->IsSelected();
			if (FigList[i]->isinside(x, y) == true)
			{
				return FigList[i];
			}
		}
	}
	pOut->PrintMessage("Selected an Empty space");
	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

void ApplicationManager::Unselect() const
{

	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->SetSelected(false);
	}
}

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
// Save all figures 
void ApplicationManager:: SaveAll(ofstream & file) const
{
	file<< FigCount<< endl;
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(file);
	}
}
// clear figure list
void ApplicationManager::ClearFigureList()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i]=NULL;

	}
	FigCount=0;
}
//get selectedfigure 
CFigure* ApplicationManager::Getselectedfig()
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i] != NULL)
		{
			if (FigList[i]->IsSelected() == true)
			{
				SelectedFig = FigList[i];
				return SelectedFig;
			}
		}
	}
}
Action* ApplicationManager::Getlastaction()
{
	return Lastaction;
}

void ApplicationManager::AddRecordaction(Action* pAct)
{
	if (Actioncount < 20)
		Recordactions[Actioncount++] = pAct;
}

void ApplicationManager::DeleteRecordAction()
{
	for (int i = 0; i < Actioncount++; i++)
	{
		delete Recordactions[i];
		Recordactions[i] = NULL;
	}
}


bool  ApplicationManager::Getrecord()
{
	return record;
}
void ApplicationManager::setrecord(bool record1)
{
	record = record1;
}


void ApplicationManager::PlayRecording()
{
	//Start excuting action by action recorded in action array
	for (int i = 0; i < Actioncount; i++)
	{
		//check if it's null or if there is an action stores
		if (Recordactions != NULL)
		{
			//excute the action and send false so it won't read parameters from user;
			Recordactions[i]->Execute(false);
			if ((i % 2) == 1)
			{
				_sleep(1000);
			}
		}
	}
	UpdateInterface();
}
// resize 
void ApplicationManager::resize(Point des)
{
	//loop to get the figure you want to resize
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			FigList[i]->resize1(des);
		}
	}
}

//return action count 
int ApplicationManager::Getactioncount()
{
	return Actioncount;
}
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	for (int i = 0; i < undocount; i++)
		delete UndoList[i];
	for (int i = 0; i < Actioncount; i++)
		delete Recordactions[i];
	for (int i = 0; i < movefigcount; i++)
		delete movefig[i];

	delete pIn;
	delete pOut;
	
}

void ApplicationManager::DeleteFigure()
{
	if (FigCount != 0)
	{
		for (int i = 0; i < FigCount; i++) // delete figure
		{
			if (FigList[i]->IsSelected() == true)
			{
				delete FigList[i];
				FigList[i] = NULL;
			}
		}
		int j = 0;
		for (int i = 0; i < FigCount; i++) // remove pointer to null by shifting
		{
			if (FigList[i] != NULL)
			{
				FigList[j] = FigList[i];
				j++;
			}
		}
		FigCount = j;

	}
}

void ApplicationManager::MoveFigure(Point des)
{

	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			orignalmovepoint = FigList[i]->getoriginalpoint();
			FigList[i]->setiswhat(2); // when iswhat =2 it indicates that the figure moved 
			if (movecheck1 == false)
			{
				moveindex1 = i;
				movecheck1 == true;
				movefig[movefigcount] = FigList[i];
				movefigcount++;
			}
			else if (movecheck2 == false && movecheck1 == true)
			{
				moveindex2 = i;
				movecheck2 = true;
				movefig[movefigcount] = FigList[i];
				movefigcount++;
			}
			FigList[i]->movefig(des);
			lastactionindex = i;
			if (FigCount == i + 1)
			{
				lastactionindex = i;
			}
			else
			{
				LastFigCount = i + 1;
			}
		}
	}

}


void ApplicationManager::addundo()
{

	if ((FigCount != 0) && (undomax == false) && (FigList[lastactionindex] != NULL))
	{
		redo = true;
		if (FigList[lastactionindex]->getiswhat() == 1)
		{
			UndoList[undocount] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
			lastactionindex = FigCount - 1;
		}
		else if (FigList[lastactionindex]->getiswhat() == 2)
		{
			FigList[lastactionindex]->movefig(orignalmovepoint);
			FigList[lastactionindex]->setiswhat(1);
			lastactionindex = FigCount - 1;

		}
		undocount++;
		if (undocount == 5)
		{
			undomax = true;
		}


	}
}

void ApplicationManager::addredo()
{
	if (undocount != 0 && FigCount < MaxFigCount && redo == true && UndoList[undocount - 1] != NULL)
	{
		FigList[FigCount] = UndoList[undocount - 1];
		UndoList[undocount - 1] = NULL;
		undocount--;
		FigCount++;
		lastactionindex = FigCount - 1;
		undomax = false;
	}
}
void ApplicationManager::ChangeColor(color newcolor)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (Filled)
		{
			pOut->setisfilled(true);
			pOut->setfillcolor(newcolor);
			if (FigList[i]->IsSelected())
				FigList[i]->ChngFillClr(newcolor);
			Filled = false;
		}
		else if (Draw)
		{
			pOut->setdrawcolor(newcolor);
			if (FigList[i]->IsSelected())
				FigList[i]->ChngDrawClr(newcolor);
			Draw = false;
		}
	}

}

void ApplicationManager::SetFilled(bool fill)
{
	Filled = fill;
}

void ApplicationManager::SetDraw(bool draw)
{
	Draw = draw;
}

void ApplicationManager::MoveFigDrag(Point des)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
		{
			FigList[i]->movefig(des);
		}
	}
}

void ApplicationManager::ClearUndo()
{
	for (int i = 0; i < undocount; i++)
	{
		delete UndoList[i];
		UndoList[i] = NULL;

	}
	undocount = 0;
}
void ApplicationManager::Clearmovefig()
{
	for (int i = 0; i < movefigcount; i++)
	{
		delete movefig[i];
		movefig[i] = NULL;

	}
	movefigcount = 0;
}

