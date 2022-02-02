#include "CutCardAction.h"

CutCardAction::CutCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CutCardAction::ReadActionParameters()
{

}

void CutCardAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Click on the desired card to cut");
	// 2- Click on the desired cell to copy its card
	CellPosition pos = pIn->GetCellClicked();
	Card* pCard = pGrid->GetCopyOfCardInCell(pos);

	// 3- if pCard is correctly (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		pGrid->SetClipboard(pCard);							//copy card to the clipboard
		pGrid->RemoveObjectFromCell(pCard->GetPosition());	//delete the original card 
		pOut->PrintMessage("Cut successfully");				//cut successfully

	}
	else
	{
		pGrid->PrintErrorMessage("The cell clicked has no card");
	}





}


CutCardAction :: ~CutCardAction()
{

}