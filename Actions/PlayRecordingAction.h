#pragma once
#include "Actions/Action.h"

class PlayRecordingAction : public Action
{
public:

private:
public:
	PlayRecordingAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute(bool c);
	~PlayRecordingAction(void);
};