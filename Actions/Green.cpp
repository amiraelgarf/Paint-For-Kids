#include "Green.h"
#include "ApplicationManager.h"



Green::Green(ApplicationManager* pApp) :Action(pApp)
{
	newcolor = GREEN;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Green");
}
void Green::ReadActionParameters()
{
}
void Green::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	pManager->ChangeColor(newcolor);
}