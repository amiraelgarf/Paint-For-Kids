#pragma once

#include "Figures/CFigure.h"
#include "ApplicationManager.h"

class C_Square : public CFigure
{
private:
	Point Po1; 
	int length;
	int iswhat; // determines if the figure is moved or changed color or deleted

public:
	C_Square();
	C_Square(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isinside(int x, int y);
	virtual void movefig(Point des);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	virtual void Save(ofstream &filename); //save the figure param to the file
	virtual void Load(ifstream &filename); //load the figure param to the file
	virtual string getFigure() const;
	virtual void resize1(Point des);
	virtual void fillcolour(color c);
	virtual void setiswhat(int iw);
	virtual int getiswhat();
	virtual Point getoriginalpoint();

};

