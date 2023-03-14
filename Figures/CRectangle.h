#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int iswhat; // determines if the figure is moved or changed color or deleted

public:
	CRectangle();
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool isinside(int x , int y);
	virtual void printinfo();
	virtual void movefig(Point des);
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar

	virtual void Save(ofstream &filename); //save the figure param to the file
	virtual void Load(ifstream &filename); //load the figure param to the file
	virtual string getFigure() const;
	virtual void resize1(Point des);
	virtual void setiswhat(int iw);
	virtual int getiswhat();
	virtual Point getoriginalpoint();

};

#endif