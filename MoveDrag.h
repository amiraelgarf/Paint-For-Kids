#pragma once
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include "DEFS.h" 
#include "CMUgraphicsLib\CMUgraphics.h"

class MoveDrag : public Action
{
private:
	Point P ;
public:	
	MoveDrag(ApplicationManager* pApp);
	void virtual ReadActionParameters();
	void virtual Execute(bool readparameters = true);
	
};