#include "PasteCardAction.h"

#include"CardOne.h"
#include"CardTwo.h"
#include"CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTweleve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

PasteCardAction::PasteCardAction(ApplicationManager* pApp) : Action(pApp)
{

}

void PasteCardAction::ReadActionParameters()
{

}

void PasteCardAction::Execute()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


   // == Here are some guideline steps (numbered below) to implement this function ==

   // 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Card* pCard = pGrid->GetClipboard();

	// 2- if pCard is correctly (i.e. if pCard is pointing to an object -- NOT NULL)
	if (pCard)
	{
		pOut->PrintMessage("Click on the desired cell to paste the card");
		// 2- Click on the desired cell to paste its card
		CellPosition pos = pIn->GetCellClicked();
		int CardNum = pCard->GetCardNumber();
		bool added;
		Card* addedCard = NULL;

		switch (CardNum)
		{
		case 1:
			addedCard = ((CardOne*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 2:
			addedCard = ((CardTwo*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 3:
			addedCard = ((CardThree*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 4:
			addedCard = ((CardFour*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 5:
			addedCard = ((CardFive*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 6:
			addedCard = ((CardSix*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 7:
			addedCard = ((CardSeven*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 8:
			addedCard = ((CardEight*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 9:
			addedCard = ((CardNine*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 10:
			addedCard = ((CardTen*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 11:
			addedCard = ((CardEleven*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 12:
			addedCard = ((CardTweleve*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 13:
			addedCard = ((CardThirteen*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		case 14:
			addedCard = ((CardFourteen*)pCard)->CopyParameters(pos);
			added = pGrid->AddObjectToCell(addedCard);
			break;
		}

		if (added == false)
		{
			pGrid->PrintErrorMessage("the Desired cell to copy the card already has an object");
		}

	}
	else
	{
		pGrid->PrintErrorMessage("There is no copied card in the clipboard to be pasted");
	}

	pOut->ClearStatusBar();
}


PasteCardAction:: ~PasteCardAction()
{

}