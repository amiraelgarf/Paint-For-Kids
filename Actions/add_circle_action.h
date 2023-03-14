#pragma once
#include "Actions/Action.h"

class add_circle_action : public Action
{
private:
	Point Center, Radius; //Rectangle Corners
	GfxInfo circGfxInfo;
public:
	add_circle_action(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool readparameters = true);

};


