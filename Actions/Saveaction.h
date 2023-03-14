#pragma once
#include "Actions/Action.h"
#include<fstream>



class Saveaction : public Action
{
private:
	string name;
	ofstream file;
public:
	//default constractor
	Saveaction(ApplicationManager *pApplication);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);

	//default destractor
	~Saveaction(void);
};