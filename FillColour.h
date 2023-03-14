#pragma once
#include "Actions/Action.h"

class FillColour :public Action
{
private:
	bool filled;
public:
	FillColour(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparamter);
	bool getfilled();
	void setfilled(bool x);

};