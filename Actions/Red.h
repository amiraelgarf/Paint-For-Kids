#pragma once
#include "Actions/Action.h"
class Red : public Action
{
private:
	color newcolor;
public:
	Red(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};
