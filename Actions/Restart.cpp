#include "Restart.h"
#include "Actions/Action.h"
#include "ApplicationManager.h"
#include <fstream>
#include "LoadAction.h"

// constructor	
restart::restart(ApplicationManager* pApp)
	:Action(pApp)
{}
void restart::ReadActionParameters()
{}
void restart::Execute(bool readparamter)
{
	pManager->Unselect();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Game will restart, please choose a game");
	ifstream Switch_to_drwa("STP.txt", ios::in);
	//loading previous figures
	LoadAction* load = new LoadAction("STP.txt", pManager);
	load->Execute(false);
}