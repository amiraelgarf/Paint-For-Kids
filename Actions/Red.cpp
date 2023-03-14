#include "Red.h"
#include "ApplicationManager.h"



Red::Red(ApplicationManager* pApp) :Action(pApp)
{
	newcolor = RED;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Red");
}
void Red::ReadActionParameters()
{
}
void Red::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	pManager->ChangeColor(newcolor);
}