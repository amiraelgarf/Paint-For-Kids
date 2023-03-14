#pragma once
#include "Actions/Action.h"
#include <fstream>
#include "LoadAction.h"

class restart : public Action
{
public:
	restart(ApplicationManager* pApp);
	void virtual ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};