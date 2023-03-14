#include "Orange.h"
#include "ApplicationManager.h"



Orange::Orange(ApplicationManager* pApp) :Action(pApp)
{
	newcolor = ORANGE;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Orange");
}
void Orange::ReadActionParameters()
{
}
void Orange::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	pManager->ChangeColor(newcolor);
}