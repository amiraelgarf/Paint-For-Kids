#include "Addhexagon.h"
#include "C_hexa.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"


Addhexagon::Addhexagon(ApplicationManager* pApp) :Action(pApp)
{}


void  Addhexagon::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Hexagon: Click at the center");

	// Playing Sound
	if (pManager->getSoundState())
	{
		PlaySound(TEXT("hexa.wav"), NULL, SND_ASYNC);
	}

	//Read center and store in point P1
	pIn->GetPointClicked(Center.x, Center.y);


	hexaGfxInfo.isFilled = pOut->getisfilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	hexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	hexaGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void Addhexagon::Execute(bool readparamter)
{
	//lw false ana b record don't read paramaters
	if (readparamter == true)
	{
		ReadActionParameters();
	}
	//Create a rectangle with the parameters read from the user
	C_hexa* R = new C_hexa(Center, hexaGfxInfo);

	//Add the hexa to the list of figures
	pManager->AddFigure(R);
	bool rec = pManager->Getrecord();
	//if ana b record add it fy el array

	if (rec == true)
	{
		pManager->AddRecordaction(this);
	}
	pManager->UpdateInterface();
}
