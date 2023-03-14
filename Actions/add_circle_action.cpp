#include "add_circle_action.h"
#include "Ccircle.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

add_circle_action::add_circle_action(ApplicationManager* pApp) :Action(pApp)
{}

void add_circle_action::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	// Playing Sound 
	if (pManager->getSoundState())
	{
		PlaySound(TEXT("circ.wav"), NULL, SND_ASYNC);
	}

	pOut->PrintMessage("New Circle: Click at center");

	pIn->GetPointClicked(Center.x, Center.y);

	pOut->PrintMessage("New Circle: Click at radius");

	pIn->GetPointClicked(Radius.x, Radius.y);

	circGfxInfo.isFilled = pOut->getisfilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	circGfxInfo.DrawClr = pOut->getCrntDrawColor();
	circGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void add_circle_action::Execute(bool readparamter)
{
	if (readparamter == true)
	{
		ReadActionParameters();
	}

	Ccircle* R = new Ccircle(Center, Radius, circGfxInfo);

	pManager->AddFigure(R);    //adding fig to array
    //if user is currently recording
	bool rec = pManager->Getrecord();
	if (rec == true)
	{
		pManager->AddRecordaction(this);
	}
	pManager->UpdateInterface();
}

