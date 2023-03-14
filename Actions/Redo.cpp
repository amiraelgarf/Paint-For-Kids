#include "Redo.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

Redo::Redo(ApplicationManager* pApp) :Action(pApp)
{
}

void Redo::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Undo");
}

void Redo::Execute(bool readparamter)
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->addredo();
}