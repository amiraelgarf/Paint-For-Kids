#pragma once
#include "Figures/CFigure.h"
class C_hexa : public CFigure
{
private:
	Point Center; //center point 
	int l; //length of hexagon side
	int iswhat; // determines if the figure is moved or changed color or deleted


public:
	C_hexa();
	C_hexa(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	//area triangle
	float area(int x, int y, int x1, int y1, int x2, int y2);
	virtual bool isinside(int x, int y);
	virtual void Save(ofstream &filename); //save the figure param to the file
	virtual void Load(ifstream &filename); //load the figure param to the file
	virtual string getFigure() const;
	virtual void movefig(Point des);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
	virtual void resize1(Point des);
	virtual void fillcolour(color c);
	virtual void setiswhat(int iw);
	virtual int getiswhat();
	virtual Point getoriginalpoint();

};
