#include "Select.h"
#include "Figures/CFigure.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

//constructor
Select::Select(ApplicationManager* pApp) :Action(pApp)
{}

void Select::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure");
	//Get point clicked
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("");


}



void Select::Execute(bool readparamter)
{
	//lw bn rec msh 3yzno 
	if (readparamter == true)
	{
		ReadActionParameters();
	}

	bool unselected = false;
	CFigure* pointer1 = pManager->GetFigure(P1.x, P1.y, unselected);
	//hyrg3 by null lw msh isinside ay haga fa check eno msh bn null
	if (pointer1 != NULL)
	{
		//unselect kolo 34an one figure selected at a time
		pManager->Unselect();
		//lw el figure dh kan selected it abl keda yba 5las 5ly unselected
		if (unselected == true)
		{
			pointer1->SetSelected(false);

		}
		else
		{
			//selecto w print el info bt3to 
			pointer1->SetSelected(true);
			Output* pOut = pManager->GetOutput();
			pointer1->PrintInfo(pOut);
		}
	}
	//add lw b record 
	bool rec = pManager->Getrecord();
	if (rec == true)
	{
		pManager->AddRecordaction(this);

	}
	pManager->UpdateInterface();
}
