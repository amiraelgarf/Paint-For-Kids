#pragma once

#include "Actions/Action.h"
class Addtriangleaction : public Action
{
private:
	Point Corner1, Corner2, Corner3; //Triangle Corners
	GfxInfo TrianGfxInfo;
public:
	Addtriangleaction(ApplicationManager* pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();

	//Add triangle to the ApplicationManager
	virtual void Execute(bool readparameters = true);

};

