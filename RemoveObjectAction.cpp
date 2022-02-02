#include "RemoveObjectAction.h"

#include "Grid.h"

RemoveObjectAction::RemoveObjectAction(ApplicationManager* pApp) : Action(pApp)
{

}

void RemoveObjectAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	pGrid->GetOutput()->PrintMessage("Click on the object you want to remove");

	pos = pGrid->GetInput()->GetCellClicked();

	pGrid->GetOutput()->ClearStatusBar();
}

void RemoveObjectAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	// 2- Find the object to be deleted 
	GameObject* pObj = pGrid->GetObjectFromCell(pos);
	
	// 3- if pObj exists
	if (pObj)
	{
		pGrid->RemoveObjectFromCell(pos);
	}
	else
	{
		pGrid->PrintErrorMessage("Cell selected has no object to be remvoed");
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->ClearStatusBar();
	}

	
	




}


RemoveObjectAction :: ~RemoveObjectAction()
{

}