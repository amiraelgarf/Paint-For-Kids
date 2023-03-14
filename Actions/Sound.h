#pragma once
#include "Actions/Action.h"

class sound : public Action
{
private:
	bool s;                                   
public:
	sound(ApplicationManager* pApp);            //constructor
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
};