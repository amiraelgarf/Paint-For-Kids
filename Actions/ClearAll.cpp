#include "ClearAll.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

ClearAll::ClearAll(ApplicationManager* pApplication): Action(pApplication)
{
}
void ClearAll::ReadActionParameters(){}

void ClearAll::Execute(bool readparameters)
{
	Output* pOut = pManager->GetOutput();
	pManager->ClearFigureList();
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
	pManager->ClearUndo();
	pManager->Clearmovefig();
	pOut->PrintMessage("Everything cleared");
	bool rec = pManager->Getrecord();
	if (rec == true)
	{
		pManager->AddRecordaction(this);
	}
	pManager->UpdateInterface();

}

ClearAll::~ClearAll(void)
{
}
