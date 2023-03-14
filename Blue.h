#pragma once
#include "Actions/Action.h"
class Blue : public Action
{
private:
	color newcolor;
public:
	Blue(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};
