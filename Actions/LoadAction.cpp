#include "LoadAction.h"
#include "Figures\CFigure.h"
#include "C_hexa.h"
#include "C_Square.h"
#include "C_triangle.h"
#include "Ccircle.h"
#include "Figures\CRectangle.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "ApplicationManager.h"


LoadAction::LoadAction(ApplicationManager* pApplication) : Action(pApplication)
{
	LFig = NULL;
}
LoadAction::LoadAction(string STP, ApplicationManager* pApplication) : Action(pApplication)
{
	name = STP;
	readparameters = false;
	LFig = NULL;
}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Load: Enter file name");
	name = pIn->GetSrting(pOut);
}
void LoadAction::Execute(bool readparameters)
{
	if (readparameters == true)
	{
		ReadActionParameters();
	}
	Output* pOut = pManager->GetOutput();
	file.open(name, ios::in);
	string DrawColor, FillColor;
	int FigCount;

	if (file.is_open()) //check if there is a file with the same name or not
	{
		pOut->ClearDrawArea();
		pManager->ClearFigureList();

		//load drawing and filling color
		file >> DrawColor >> FillColor;
		pOut->getCrntDrawColor().String_to_Color(DrawColor);

		//check if ther was a filling color 
		if (FillColor != "False")
		{
			pOut->setDefFill(true);
			pOut->getCrntFillColor().String_to_Color(FillColor);
		}
		else
			pOut->setDefFill(false);
		string Figure;
		int FCount;
		//load figure count
		file >> FigCount;

		while (file >> Figure)
		{
			if (Figure == "CIRCLE")
				LFig = new Ccircle;
			else if (Figure == "HEXAGON")
				LFig = new C_hexa;
			else if (Figure == "TRIANGLE")
				LFig = new C_triangle;
			else if (Figure == "SQUARE")
				LFig = new C_Square;
			else if (Figure == "RECTANGLE")
				LFig = new CRectangle;

			if (LFig != NULL)
			{
				LFig->Load(file);
				pManager->AddFigure(LFig);
			}
			LFig = NULL;
		}
		file.close();
		pOut->ClearStatusBar();
		pOut->PrintMessage("file loaded");

	}
	else
		pOut->PrintMessage("Error");
}
/*
void LoadAction::LoadForPlay()
{
	Output* pOut; //= pManager->GetOutput();
	Switch_to_play.open("STP.txt", ios::in);
	string DrawColor, FillColor;

		pOut->ClearDrawArea();
		pManager->ClearFigureList();

		//load drawing and filling color
		Switch_to_play >> DrawColor >> FillColor;
		pOut->getCrntDrawColor().String_to_Color(DrawColor);

		//check if ther was a filling color
		if (FillColor != "False")
		{
			pOut->setDefFill(true);
			pOut->getCrntFillColor().String_to_Color(FillColor);
		}
		else
			pOut->setDefFill(false);
		string Figure;
		int FigCount;
		//load figure count
		Switch_to_play >> FigCount;

		for (int i = 0; i < FigCount; i++)
		{
			if (Figure == "CIRCLE")
				LFig = new Ccircle;
			else if (Figure == "HEXAGON")
				LFig = new C_hexa;
			else if (Figure == "TRIANGLE")
				LFig = new C_triangle;
			else if (Figure == "SQUARE")
				LFig = new C_Square;
			else if (Figure == "RECTANGLE")
				LFig = new CRectangle;

			if (LFig != NULL)
			{
				LFig->Load(Switch_to_play);
				pManager->AddFigure(LFig);
			}
			LFig = NULL;
		}
		Switch_to_play.close();
		pOut->ClearStatusBar();
}
*/