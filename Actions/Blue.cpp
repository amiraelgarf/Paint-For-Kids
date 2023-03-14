#include "Blue.h"
#include "ApplicationManager.h"



Blue::Blue(ApplicationManager* pApp) :Action(pApp)
{
	newcolor = BLUE;
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Blue");
}
void Blue::ReadActionParameters()
{
}
void Blue::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	pManager->ChangeColor(newcolor);
}