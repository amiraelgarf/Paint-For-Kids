#include "DrawColor.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"


DrawColor::DrawColor(ApplicationManager* pApp) :Action(pApp)
{
	Draw = true;
}

void DrawColor::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Choose a drawing color");
}

void DrawColor::Execute(bool readparamter)
{
	
		ReadActionParameters();

	pManager->SetDraw(Draw);
}
bool DrawColor::getdraw()
{
	return Draw;
}
void DrawColor::setdraw(bool x)
{
	Draw = x;
}