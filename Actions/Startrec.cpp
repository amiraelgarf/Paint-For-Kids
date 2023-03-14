#include "StartRec.h"
#include "ApplicationManager.h"
#include "ClearAll.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
//constructor 
StartRec::StartRec(ApplicationManager* pApp) :Action(pApp)
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Recording Started");
}

void StartRec::ReadActionParameters()
{
}

//Execute the actions
void StartRec::Execute(bool readparamter)
{
	Output* pOut = pManager->GetOutput();
	//get last action 34an lw b clear all y record
	Action* R = pManager->Getlastaction();
	//dynamic cast a4of lw b clear all
	ClearAll* p = dynamic_cast <ClearAll*> (R);
	//lw a5r action null lesa bda2 aw clear all yba rec
	if (R == NULL || p != NULL)
	{
		//lw a5r action kan clear 
		if (p != NULL)
		{
			//delete el rec action 34an el array ybda2 3la ndfa 
			pManager->DeleteRecordAction();
		}
		//w a3ml el boolen true hbda2 a rec
		pOut->PrintMessage("REC started");
		pManager->setrecord(true);
	}
	else
	{
		//lw la don't rec ba aslan
		pOut->PrintMessage("Can't Record");
		pManager->setrecord(false);
	}
	pManager->UpdateInterface();
}
