#pragma once
#include "Actions/Action.h"
#include <fstream>

class SwitchToPlayMode : public Action
{
	ofstream Switch_to_play;
public:
	SwitchToPlayMode(ApplicationManager* pApplication);
	virtual void ReadActionParameters(); 

	virtual void Execute(bool readparameters = true);

	~SwitchToPlayMode(void);
};

