#pragma once
#include "Actions/Action.h"
#include"GUI/Input.h"
#include "GUI/Output.h"
class Select : public Action
{
private:
	Point P1;
public:
	Select(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparamter = true);
};

