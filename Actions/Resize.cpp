#include "Resize.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include "ApplicationManager.h"

//Constructor
Resize::Resize(ApplicationManager* pApp) :Action(pApp)
{

}

void Resize::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	//Get point clicked
	pIn->GetPointClicked(p.x, p.y);
}

void Resize::Execute(bool readparamter)
{
	//don't read lw b record
	if (readparamter = true)
	{
		ReadActionParameters();
	}
	pManager->resize(p);
}
//get el selected point 
Point Resize::getSelectedPoint()
{
	return p;
}