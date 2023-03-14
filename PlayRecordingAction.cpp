#include "PlayRecordingAction.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

//Constructor
PlayRecordingAction::PlayRecordingAction(ApplicationManager* pApplication) : Action(pApplication)
{
}
//We won't read anything from user
void PlayRecordingAction::ReadActionParameters()
{}

void PlayRecordingAction::Execute(bool c)
{
	Output* pOut = pManager->GetOutput();
	int count = pManager->Getactioncount();
	//if count is equal to there there isn't any action recorded so print Can't play
	if (count != 0)
	{
		//clear everything
		pManager->ClearFigureList();
		pOut->ClearDrawArea();
		pOut->ClearStatusBar();
		pManager->ClearUndo();
		pManager->Clearmovefig();

		//play the actions
		pManager->PlayRecording();
		pManager->UpdateInterface();

	}
	else
	{
		pOut->PrintMessage("Can't play anything as there isn't anything recorded");
	}



}

PlayRecordingAction::~PlayRecordingAction(void)
{
}