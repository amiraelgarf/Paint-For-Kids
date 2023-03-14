#include "SwitchToPlayMode.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "ApplicationManager.h"

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApplication) : Action(pApplication)
{
}

void SwitchToPlayMode::ReadActionParameters()
{

}
void SwitchToPlayMode::Execute(bool readparameters)
{

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switch to play mode");
	UI.InterfaceMode = MODE_PLAY;
	pOut->Cleartoolbar();


	//saving previous figures

	ofstream file;
	file.open("STP.txt", ios::out);
	if (pOut->getDefFill() == false)
	{
		file << (pOut->getCrntDrawColor()).Color_to_String() << "  " << "No_Fill" << endl;
	}
	else
		file << (pOut->getCrntDrawColor()).Color_to_String() << "  " << (pOut->getCrntFillColor()).Color_to_String() << endl;

	pManager->SaveAll(file);
	file.close();
	pOut->CreatePlayToolBar();

}

SwitchToPlayMode::~SwitchToPlayMode(void)
{
}
