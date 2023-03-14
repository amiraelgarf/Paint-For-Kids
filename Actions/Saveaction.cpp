#include "Saveaction.h"
#include "Figures\CFigure.h"
#include <fstream>
#include <string>
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"


Saveaction::Saveaction(ApplicationManager *pApplication): Action(pApplication)
{

}

void Saveaction:: ReadActionParameters()
{
	//GET A POINTER TO THE INPUT & OUTPUT CLASSES
	Output* pOut= pManager->GetOutput();
	Input*pIn = pManager->GetInput();
	pOut->PrintMessage("Save: Enter file name ");
	name = pIn->GetSrting(pOut);

	pOut->PrintMessage("File Saved ");
}

void Saveaction::Execute(bool readparameters)
{
	Output* pOut= pManager->GetOutput();
	ReadActionParameters();
	ofstream file;
	file.open(name, ios::out);
	if(pOut->getDefFill()==false)
	{
		file<< (pOut->getCrntDrawColor()).Color_to_String()<< "  "<<"No_Fill"<< endl;
	}
	else
		file<< (pOut->getCrntDrawColor()).Color_to_String()<<"  "<<(pOut->getCrntFillColor()).Color_to_String()<< endl;

	pManager->SaveAll(file);
	file.close();
}

Saveaction::~Saveaction(void)
{
}