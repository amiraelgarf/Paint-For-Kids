#pragma once
#include "Figures/CFigure.h"
class Ccircle : public CFigure
{
private:
	Point Center;
	Point Radius;
	int iswhat; // determines if the figure is moved or changed color or deleted
public:
	Ccircle();
	Ccircle(Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool isinside(int x, int y);
	Point getRadius(); // gets radius 
	virtual void movefig(Point des); // sets new center if figure moved 
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	virtual string getFigure() const;
	virtual void Save(ofstream &filename); //save the figure param to the file
	virtual void Load(ifstream &filename); //load the figure param to the file
	virtual void resize1(Point des);
	virtual void setiswhat(int iw);
	virtual int getiswhat();
	virtual Point getoriginalpoint();

};
