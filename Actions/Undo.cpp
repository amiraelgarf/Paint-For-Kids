#include "Undo.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

Undo::Undo(ApplicationManager* pApp) :Action(pApp)
{
}

void Undo::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Undo");
}

void Undo::Execute(bool readparamter)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->addundo();
}