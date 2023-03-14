#include "Actions/Action.h"
#include "ApplicationManager.h"
#include "GUI\Output.h" 
#include "GUI/Input.h"
#include "Figures/CFigure.h"

class Resize : public Action
{
private:
	Point p;  // points of the new place 
public:
	Resize(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool readparameters = true);
	Point getSelectedPoint();
};
