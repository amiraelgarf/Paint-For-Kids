#include "PickByFig.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CRectangle.h"
#include "C_hexa.h"
#include "Ccircle.h"
#include "C_triangle.h"
#include "C_Square.h"

// constructor	
pickfig::pickfig(ApplicationManager* pApp)
	:PickHide(pApp)
{
	correct = 0;                                                            //counter of correct selects
	incorrect = 0; 
}


void pickfig::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	do {
		C = pManager->GetRandomFigure();                                   // determining fig type criteria
		count = pManager->getCorrectCount(C, 't');
	} while (count == 0);                                                //max no. of correct clicks 
	pOut->PrintMessage("Pick Figures of type " + getFigType(C) + " click anywhere to start");
	pIn->GetPointClicked(p.x, p.y);
	pOut->PrintMessage("Game Started");
	// pManager->Unselect(); 
}
void pickfig::Execute(bool readparamter)
{
	if (readparamter == true)
	{
		ReadActionParameters();
	}
	bool u = 1;                                        //dummy parameter 
	do {
		Input* pIn = pManager->GetInput();
		pIn->GetPointClicked(p.x, p.y);                                   //get x,y clicked to be used in get fig
		pManager->GetFigure(p.x, p.y, u);                               //checking whether the user clicked a figure
		if ((pManager->GetFigure(p.x, p.y, u)) == NULL)                //user did not click a figure
		{
			incorrect++;
		}
		else if (!(sameType(pManager->GetFigure(p.x, p.y, u), C)))    //user clicked wrong figure
		{
			incorrect++;
		}
		else if (sameType(pManager->GetFigure(p.x, p.y, u), C))        //user selected right fig
		{
			//pManager->Unselect(); 
				/*(pManager->GetFigure(p.x, p.y, u))->SetSelected(true);
				pManager->DeleteFigure();*/
				pManager->DeleteFigPlay(pManager->GetFigure(p.x, p.y, u));
			correct++;
		}
		pManager->UpdateInterface();
	} while (correct < count);
	PrintResult(correct, incorrect);
	//pManager->Unselect();
}