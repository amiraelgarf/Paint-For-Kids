#pragma once
#include "Actions/Action.h"
//bn record kol el actions m3ada start/stop recording, play recording, save graph, load graph, switch, and exit

class StartRec: public Action
{
	private:
	public:
		StartRec(ApplicationManager* pApp);

		//Reads rectangle parameters
		virtual void ReadActionParameters();

		//Add rectangle to the ApplicationManager
		virtual void Execute(bool readparameters = true);



};


