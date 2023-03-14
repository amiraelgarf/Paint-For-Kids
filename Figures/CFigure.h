#ifndef CFIGURE_H
#define CFIGURE_H
#include <fstream>

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	static int figureCount;
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
 
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	void SetID(int id);
	int GetID();

	virtual bool isinside(int x,int y);
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual string getFigure() const=0; //to know what is the figure clicked on
	///////// ADDED /////////
	color* getColor();

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	virtual void resize1(Point des) = 0; 
	virtual void movefig(Point des) = 0;
	virtual void setiswhat(int iw) = 0;
	virtual int getiswhat() = 0;
	virtual Point getoriginalpoint() = 0;

};

#endif