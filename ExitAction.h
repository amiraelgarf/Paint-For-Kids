#pragma once
#include "Actions/Action.h"

class ExitAction: public Action
{
public:
	ExitAction(ApplicationManager* pApplication);

	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
	~ExitAction(void);
};

