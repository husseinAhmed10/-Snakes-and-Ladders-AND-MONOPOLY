#include "EditCardAction.h"

#include "Input.h"
#include "Output.h"
#include "CardOne.h"
#include "CardTwo.h"
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

EditCardAction::EditCardAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

EditCardAction::~EditCardAction()
{
}

void EditCardAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read the "cardPosition" parameter (its cell position) to edit
	pOut->PrintMessage("Please select the cell to edit position:");
	cardPosition = pIn->GetCellClicked();
	pCard = pGrid->GetCopyOfCardInCell(cardPosition);

	if (pCard == NULL)		//select empty cell
	{
		pGrid->PrintErrorMessage("NO Card in this Cell, Click anywhere to continue");
		pOut->ClearStatusBar();
		return;
	}
	// 4- Make the needed validations on the read parameters
	cardNumber = pCard->GetCardNumber();
	if (cardNumber >= 3 && cardNumber <= 8)
	{
		pGrid->PrintErrorMessage("This card can't be edited");
		pCard = NULL;
	}
	
	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void EditCardAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- The first line of any Action Execution is to read its parameter first
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	// 2- Edit card object type
	if (pCard != NULL)
	{
		if (dynamic_cast<CardTen*>(pCard))
		{
			((CardTen*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardEleven*>(pCard))
		{
			((CardEleven*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardTweleve*>(pCard))
		{
			((CardTweleve*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardThirteen*>(pCard))
		{
			((CardThirteen*)pCard)->EditParametersInCard10(pGrid);
		}
		else if (dynamic_cast<CardFourteen*>(pCard))
		{
			((CardFourteen*)pCard)->EditParametersInCard10(pGrid);
		}
		else
		{
			pCard->ReadCardParameters(pGrid);
		}
	}

	// Here, the card is created and added to the GameObject of its Cell, so we finished executing the AddCardAction

}

