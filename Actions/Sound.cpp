#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "Sound.h"


// constructor	
sound::sound(ApplicationManager* pApp)
	:Action(pApp)
{}

void sound::ReadActionParameters()
{}
void sound::Execute(bool readparameters)
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Clicking on the Mute/UnMute Button");
	pManager->switchSoundState();
	s = pManager->getSoundState();
	if (s == 1)
		pOut->PrintMessage("Sound ON");
	else
		pOut->PrintMessage("Sound OFF");
}
