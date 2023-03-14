#pragma once
#include "Actions/Action.h"

class ClearAll: public Action
{
public:
	private:
	public:
		ClearAll(ApplicationManager* pApplication);
		virtual void ReadActionParameters();
		virtual void Execute(bool readparameters = true);
	~ClearAll(void);
};

