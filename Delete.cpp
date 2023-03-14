#include "Delete.h"
#include "ApplicationManager.h"
#include "GUI\Output.h" 

Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{}

void Delete::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Figure selected deleted");
}

void Delete::Execute(bool readparamter)
{
	//don't read if false, this means recording is on
	if (readparamter == true)
	{
		ReadActionParameters();
	}
	pManager->DeleteFigure();

	bool rec = pManager->Getrecord();
	if (rec == true)
	{
		pManager->AddRecordaction(this);
	}
	pManager->UpdateInterface();
}