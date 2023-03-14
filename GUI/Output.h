#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
	bool isfilled;

public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void Cleartoolbar() const; // clears the tool bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle

	///Make similar functions for drawing all other figure types.
	void DrawCircle(Point P1, Point P2, GfxInfo circleGfxInfo, bool selected = false) const; // Draw Circle
	void DrawSquare(Point P1, GfxInfo SquareGfxInfo, int length, bool selected = false) const; //Draw Square
	void DrawHexa(Point P1, GfxInfo HexaGfxInfo, int l, bool selected = false) const; // Draw Hexagom
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected = false) const; // Draw Triangle

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width
	void setDefFill(bool color);// set the default to draw figure filling
	bool getDefFill();// is the default to draw fig fill?

	void setfillcolor(color newcolor);
	void setisfilled(bool t);
	bool getisfilled();
	void setdrawcolor(color newcolor);

	~Output();
};

#endif