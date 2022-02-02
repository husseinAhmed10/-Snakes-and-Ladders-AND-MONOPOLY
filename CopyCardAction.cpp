#include "CopyCardAction.h"

CopyCardAction:: CopyCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void CopyCardAction::ReadActionParameters()
{

 }

 void CopyCardAction::Execute()
 {

	 ///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	 // == Here are some guideline steps (numbered below) to implement this function ==

	 // 1- The first line of any Action Execution is to read its parameter first
	 ReadActionParameters();
	 Grid* pGrid = pManager->GetGrid();
	 Input* pIn = pGrid->GetInput();
	 Output* pOut = pGrid->GetOutput();
	 pOut->PrintMessage("Click on the desired card to copy");
	 // 2- Click on the desired cell to copy its card
	 CellPosition pos = pIn->GetCellClicked();
	 Card* pCard = pGrid->GetCopyOfCardInCell(pos);


	 // 3- if pCard is correctly (i.e. if pCard is pointing to an object -- NOT NULL)
	 if (pCard)
	 {
		 pGrid->SetClipboard(pCard);			//copy card to the clipboard
		 pOut->PrintMessage("Copied successfully");

	 }
	 else
	 {
		 pGrid->PrintErrorMessage("The cell clicked has no card");
	 }


 }
						

 CopyCardAction :: ~CopyCardAction()
 {

 }