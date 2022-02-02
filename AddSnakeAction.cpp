#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters
	if (endPos.HCell() != startPos.HCell())
	{
		pGrid->PrintErrorMessage("end cell and start cell are not in the same column");
	}
	if (endPos.VCell() <= startPos.VCell())
	{
		pGrid->PrintErrorMessage("end cell must be below start cell");
	}
	if (pGrid->GetLadderFromPosition(endPos) != NULL)
	{
		pGrid->PrintErrorMessage("End position can't be the start of a ladder");
	}


	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Snake object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	if (endPos.HCell() != startPos.HCell())
	{
		return;
	}
	if (startPos.VCell() == endPos.VCell())
	{
		return;
	}
	if (endPos.VCell() <= startPos.VCell())
	{
		return;
	}
	if (pGrid->GetLadderFromPosition(endPos) != NULL)
	{
		return;
	}
	if (pGrid->IsOverLapping(pSnake))
	{
		pGrid->PrintErrorMessage("Two Snakes cannot overlap");
		return;
	}


	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the Snake is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
