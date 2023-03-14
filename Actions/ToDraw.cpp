#include "ToDraw.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include <fstream>
#include "LoadAction.h"

toDraw::toDraw(ApplicationManager* pApp)
	:Action(pApp)
{}

void toDraw::ReadActionParameters()
{}
void toDraw::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switch to Draw Mode");
	UI.InterfaceMode = MODE_DRAW;
	pOut->Cleartoolbar();
	ifstream Switch_to_drwa("STP.txt", ios::in);
	//loading previous figures
	LoadAction* load = new LoadAction("STP.txt", pManager);
	load->Execute(false);
	//load->LoadForPlay();
	pOut->CreateDrawToolBar();
}
