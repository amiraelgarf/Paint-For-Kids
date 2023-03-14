#pragma once
#include "Actions/Action.h" 
class DrawColor : public Action
{
private:
	bool Draw;
public:
	DrawColor(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparamter);
	bool getdraw();
	void setdraw(bool x);

};