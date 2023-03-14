#pragma once
#include "Actions/Action.h"
class Black : public Action
{
private:
	color newcolor;
public:
	Black(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};