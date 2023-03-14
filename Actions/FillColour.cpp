#include "FillColour.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"


FillColour::FillColour(ApplicationManager* pApp) :Action(pApp)
{
	filled = true;
}

void FillColour::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Choose a filling color");
}

void FillColour::Execute(bool readparamter)
{
	
		ReadActionParameters();
	
	pManager->SetFilled(filled);
	
}
bool FillColour::getfilled()
{
	return filled;
}
void FillColour::setfilled(bool x)
{
	filled = x;
}