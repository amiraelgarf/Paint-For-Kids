#include "PickByBoth.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "Figures/CRectangle.h"
#include "C_hexa.h"
#include "Ccircle.h"
#include "C_triangle.h"
#include "C_Square.h"

// constructor	
pickboth::pickboth(ApplicationManager* pApp)
	:PickHide(pApp)
{
	correct = 0;                                                            //counter of correct selects
	incorrect = 0; 
}

void pickboth::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	C = pManager->GetRandomFigure();                                  // determining fig clr criteria
	count = pManager->getCorrectCount(C, 'b');                        //max no. of correct clicks 
	if (count == 0)
		pOut->PrintMessage("All Figures are NOT FILLED, Please choose another game");
	else
	{
		pOut->PrintMessage("Pick Figures of type " + getFigType(C) + "and colour " + getColourName(C) + " click anywhere to start");
		pIn->GetPointClicked(p.x, p.y);
		pOut->PrintMessage("Game Started");
	}
}
void pickboth::Execute(bool readparamter)
{
	if (readparamter == true)
	{
		ReadActionParameters();
	}
	if (count != 0)
	{
		bool u = 1;                                                  //dummy parameter
		do {
			Input* pIn = pManager->GetInput();
			pIn->GetPointClicked(p.x, p.y);                                   //get x,y clicked to be used in get fig	
			pManager->GetFigure(p.x, p.y, u);                               //checking whether the user clicked a figure
			if ((pManager->GetFigure(p.x, p.y, u)) == NULL)                //user did not click a figure
			{
				incorrect++;
			}
			else if (!(sameclr(pManager->GetFigure(p.x, p.y, u), C)) || !(sameType(pManager->GetFigure(p.x, p.y, u), C)))    //user clicked fig with wrong color
			{
				incorrect++;
			}
			else if ((sameclr(pManager->GetFigure(p.x, p.y, u), C)) && (sameType(pManager->GetFigure(p.x, p.y, u), C)))        //user selected fig with right color
			{
				/*pManager->Unselect();
				(pManager->GetFigure(p.x, p.y, u))->SetSelected(true);
				pManager->DeleteFigure();*/
				pManager->DeleteFigPlay(pManager->GetFigure(p.x, p.y, u));
				correct++;
			}
			pManager->UpdateInterface();
		} while (correct < count);
		PrintResult(correct, incorrect);
		//pManager->Unselect(); 
	}
}
