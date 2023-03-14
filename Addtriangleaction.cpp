#include "Addtriangleaction.h"
#include "C_triangle.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

Addtriangleaction::Addtriangleaction(ApplicationManager* pApp) :Action(pApp)
{}

void Addtriangleaction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1
	pIn->GetPointClicked(Corner1.x, Corner1.y);
	pOut->PrintMessage("New Triangle: Click at second corner");
	
	// Playing Sound 
	if (pManager->getSoundState())
	{
		PlaySound(TEXT("triangle.wav"), NULL, SND_ASYNC);
	}
	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(Corner2.x, Corner2.y);

	pOut->PrintMessage("New Triangle: Click at Third corner");

	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(Corner3.x, Corner3.y);

	TrianGfxInfo.isFilled = pOut->getisfilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TrianGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TrianGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void Addtriangleaction::Execute(bool readparamter)
{
	//This action needs to read some parameters first
	if (readparamter == true)
	{
		ReadActionParameters();
	}
	//Create a triangle with the parameters read from the user
	C_triangle* R = new C_triangle(Corner1, Corner2, Corner3, TrianGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(R);
	bool rec = pManager->Getrecord();
	if (rec == true)
	{
		pManager->AddRecordaction(this);
	}
}
