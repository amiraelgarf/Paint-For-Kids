#pragma once
#include "Actions/Action.h"
class Yellow : public Action
{
private:
	color newcolor;
public:
	Yellow(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};

