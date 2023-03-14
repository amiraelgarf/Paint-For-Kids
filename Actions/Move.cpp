#include "Move.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{

}
void Move::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Click where you want to move the figure");
	pIn->GetPointClicked(pmove.x, pmove.y);
}

void Move::Execute(bool readparamter)
{
	//don't read paramaters if we are recording 
	if (readparamter == true)
	{
		ReadActionParameters();
	}
	//Move the figure 
	pManager->MoveFigure(pmove);

	Output* pOut = pManager->GetOutput();
	bool rec = pManager->Getrecord();
	//record the action if rec button was selected
	if (rec == true)
	{
		pManager->AddRecordaction(this);
		pOut->PrintMessage("Move recorded");

	}
}

Point Move::getSelectedPoint()
{
	return pmove;
}
