#include "InputDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include"CardSeven.h"
#include"CardEight.h"

InputDiceAction::InputDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void InputDiceAction::ReadActionParameters()
{
	if (pManager->GetGrid()->GetEndGame() == true)
	{
		pManager->GetGrid()->PrintErrorMessage("End Game    For New Game or Exit or Return to Design Mode, press its icon in Toolbar");
		return;
	}

	pManager->GetGrid()->GetOutput()->PrintMessage("Please enter a dice value between 1-6 :");
	DiceNum = pManager->GetGrid()->GetInput()->GetInteger(pManager->GetGrid()->GetOutput());
	if (DiceNum <= 0 || DiceNum > 6)
	{
		pManager->GetGrid()->PrintErrorMessage("Invalid dice number");
		return;
	}

}

void InputDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==
	ReadActionParameters();

	if (DiceNum < 0 || DiceNum>6)
	{
		return;
	}
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	// 2- Get the "current" player from pGrid
	Player* pPlayer = pGrid->GetCurrentPlayer();
	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pManager->GetGrid()->GetEndGame() == true)
	{
		pManager->GetGrid()->PrintErrorMessage("End Game    For New Game or Exit or Return to Design Mode, press its icon in Toolbar");
		return;
	}
	// -- If not ended, do the following --:
	Card* pCard = pPlayer->GetCell()->HasCard();
	if (pCard)
	{
		CardEight* pCard2 = dynamic_cast<CardEight*>(pCard);
		if (pCard2)
		{
			//pCard2->Apply(pGrid, p);
			if (pCard2->GetStatues(pPlayer->GetPlayerNum()) == false)
			{
				pCard2->convertion(pPlayer->GetPlayerNum());
				pPlayer->Move(pManager->GetGrid(), 0);
				return;
			}
		}
	}
	// 4- Move the currentPlayer using function Move of class player
	pPlayer->Move(pManager->GetGrid(), DiceNum);
	pCard = pPlayer->GetCell()->HasCard();
	if (pCard)
	{
		CardSeven* pCard2 = dynamic_cast<CardSeven*>(pCard);
		if (pCard2)
		{
			//pCard2->Apply(pGrid,p);
			return;
		}
	}

	// 4- Advance the current player number of pGrid
	pManager->GetGrid()->AdvanceCurrentPlayer();

	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	if (pManager->GetGrid()->GetEndGame() == true)
	{
		pManager->GetGrid()->PrintErrorMessage("End Game    For New Game or Exit or Return to Design Mode, press its icon in Toolbar");
		return;
	}
}

InputDiceAction::~InputDiceAction()
{
}