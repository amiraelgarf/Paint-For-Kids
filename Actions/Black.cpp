#include "Black.h"
#include "ApplicationManager.h"



Black::Black(ApplicationManager* pApp) :Action(pApp)
{
	newcolor = BLACK;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Black");
}
void Black::ReadActionParameters()
{
}
void Black::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	pManager->ChangeColor(newcolor);
}