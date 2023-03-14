#include "Add_sqaure_action.h"


#include "C_Square.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"


Add_sqaure_action::Add_sqaure_action(ApplicationManager* pApp) :Action(pApp)
{}


void  Add_sqaure_action::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Sqaure: Click at the center");
	
	// Playing Sound 
	if (pManager->getSoundState())
	{
		PlaySound(TEXT("square.wav"), NULL, SND_ASYNC);
	}
	//Read centre and store in point P1
	pIn->GetPointClicked(Po1.x, Po1.y);


	SqrGfxInfo.isFilled = pOut->getisfilled();;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void Add_sqaure_action::Execute(bool readparamter)
{
	//This action needs to read some parameters first
	if (readparamter == true)
	{
		ReadActionParameters();
	}
	//Create a square with the parameters read from the user
	C_Square* R = new C_Square(Po1, SqrGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(R);
    //if user is currecntly recording
	bool rec = pManager->Getrecord();
	if (rec == true)
	{
		pManager->AddRecordaction(this);
	}
	pManager->UpdateInterface();
}