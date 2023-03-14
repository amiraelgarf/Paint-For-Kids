#pragma once
#include "Actions/Action.h"
class Orange : public Action
{
private:
	color newcolor;
public:
	Orange(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};

