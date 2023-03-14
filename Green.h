#pragma once
#include "Actions/Action.h"
class Green : public Action
{
private:
	color newcolor;
public:
	Green(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};

