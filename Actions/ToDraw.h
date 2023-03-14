#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include <fstream>
#include "LoadAction.h"

class toDraw : public Action
{
	
public:
	// constructor	
	toDraw(ApplicationManager* pApp);
	void virtual ReadActionParameters();
	void virtual Execute(bool readparameters = true);
};