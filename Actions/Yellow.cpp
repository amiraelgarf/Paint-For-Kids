#include "Yellow.h"
#include "ApplicationManager.h"



Yellow::Yellow(ApplicationManager* pApp) :Action(pApp)
{
	newcolor = YELLOW;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Yellow");
}
void Yellow::ReadActionParameters()
{
}
void Yellow::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	pManager->ChangeColor(newcolor);
}