#include "MoveDrag.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"


MoveDrag::MoveDrag(ApplicationManager* pApp)
	:Action(pApp)
{}
void MoveDrag::ReadActionParameters()
{

}
void MoveDrag::Execute(bool readparamter)
{
	CFigure* C;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Press on a figure to move then press again to release");
	pIn->GetPointClicked(P.x, P.y);
	bool u = 1;          //dummy parameter
	pManager->Unselect();
	C = pManager->GetFigure(P.x, P.y, u);
	if (C != NULL)
	{
		C->SetSelected(true);
	}
	do {
		//ptr->GetMouseClick(P.x, P.y); 
		pIn->GetMouseCrdnts(P.x, P.y);
		pManager->MoveFigDrag(P);
		pManager->UpdateInterface();
		//pManager->Unselect();
		//pIn->GetPointClicked(P.x, P.y);
		//break;
		u = !(pIn->MouseClick(P.x, P.y));
	} while (u == 1);
}