#include "ExitAction.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"

ExitAction::ExitAction(ApplicationManager* pApplication): Action(pApplication)
{
}

void ExitAction:: ReadActionParameters()
{
	Output* pOut= pManager->GetOutput();
	pOut->PrintMessage("EXIT");
	pOut->ClearStatusBar();
}

void ExitAction:: Execute(bool readparameters)
{
	Output*pOut= pManager->GetOutput();
	pManager->ClearFigureList();
	ReadActionParameters();
}
ExitAction::~ExitAction(void)
{
}
