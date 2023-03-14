#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions/Action.h"
#include <Windows.h>

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	int undocount;    // number of undos 

	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	Action* Recordactions[20]; 
	Action* Lastaction;
	int Actioncount; 
	bool undomax; // did undo reach maximum operation?
	bool redo;  // can redo work or not 
	int moveindex1; // gets first index of move action for undo and redo
	int moveindex2; // gets secound index of move action for undo and redo
	bool movecheck1; // checks if moveindex1 is used
	bool movecheck2; // checks if moveindex2 is used 
	CFigure* movefig[2]; // stores original moved figure
	int movefigcount; // count of moved figures in the movefig array 
	bool record;
	bool mute_not;                //states wether current state is mute or unmute, sound is on by default
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	Point orignalmovepoint;
	CFigure* UndoList[5]; // list of all undo figures ( array of pointers)
	bool Filled;
	bool Draw;
	int lastactionindex; // last action figure index 
	int LastFigCount; // stores last figcount before any action occurs 


public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it

	////////////// ADDED //////////////
	CFigure* GetRandomFigure(); //returns a random figure from FigList to use in pick&hide
	/*CFigure* getFigList(int index);
	int getFigCount(); */
	void DeleteFigPlay(CFigure* C);
	int getCorrectCount(CFigure* C, char criteria);
	bool getSoundState();
	void setSoundState(bool s);
	void switchSoundState();
	/*bool sameclr(CFigure* C, CFigure* F);
	bool sameType(CFigure* C, CFigure* F);*/
	//////////////////////////////////////
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y, bool &unselect) const; //Search for a figure given a point inside the figure
	void Unselect() const;

	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	Action* Getlastaction();
	CFigure* Getselectedfig();
	void AddRecordaction(Action* pAct);
	void DeleteRecordAction();
	bool Getrecord();
	void setrecord(bool record); 
	void DeleteFigure();  //deletes selected figure 
	void MoveFigure(Point des); // moves figure
	void SaveAll(ofstream &file) const; //
	void ClearFigureList();
	void PlayRecording(); //play recording fun
	void resize(Point des); // resize ay figure 
	int Getactioncount(); //get the no of actions recorded
	void addundo(); // adds undoed figure in undo array
	void addredo(); // puts undoed figurs in figurelist
	void ChangeColor(color newcolor); // changes fill or draw color 
	void SetFilled(bool fill);  // sets fill
	void SetDraw(bool draw); // sets draw 
	void MoveFigDrag(Point des); // moves figure
	void ClearUndo();
	void Clearmovefig();

};

#endif