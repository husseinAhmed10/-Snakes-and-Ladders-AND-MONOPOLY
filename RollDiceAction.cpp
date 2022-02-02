#include "RollDiceAction.h"

#include "Grid.h"
#include "Player.h"
#include "Card.h"
#include"CardSeven.h"
#include"CardEight.h"


#include <time.h> // used to in srand to generate random numbers with different seed

RollDiceAction::RollDiceAction(ApplicationManager* pApp) : Action(pApp)
{
}

void RollDiceAction::ReadActionParameters()
{
	// no parameters to read from user
}

void RollDiceAction::Execute()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Check if the Game is ended (Use the GetEndGame() function of pGrid), if yes, make the appropriate action
	if (pManager->GetGrid()->GetEndGame() == true)
	{
		pManager->GetGrid()->PrintErrorMessage("End Game    For New Game or Exit or Return to Design Mode, press its icon in Toolbar");
		return;
	}
	// -- If not ended, do the following --:

	// 2- Generate a random number from 1 to 6 --> This step is done for you
	srand((int)time(NULL)); // time is for different seed each run
	int diceNumber = 1 + rand() % 6; // from 1 to 6 --> should change seed

	// 3- Get the "current" player from pGrid
	Player* pPlayer = pManager->GetGrid()->GetCurrentPlayer();
	
	Card* pCard = pPlayer->GetCell()->HasCard();
	if (pCard)
	{
		CardEight* pCard2 = dynamic_cast<CardEight*>(pCard);
		if (pCard2)
		{
			if (pCard2->GetStatues(pPlayer->GetPlayerNum()) == false)
			{
				pCard2->convertion(pPlayer->GetPlayerNum());
				pPlayer->Move(pManager->GetGrid(), 0);
				return;
			}
		}
	}
	// 4- Move the currentPlayer using function Move of class player
	pPlayer->Move(pManager->GetGrid(), diceNumber);
	// 5- Advance the current player number of pGrid
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
	pManager->GetGrid()->AdvanceCurrentPlayer();
	// NOTE: the above guidelines are the main ones but not a complete set (You may need to add more steps).
	if (pManager->GetGrid()->GetEndGame() == true)
	{
		pManager->GetGrid()->PrintErrorMessage("End Game    For New Game or Exit or Return to Design Mode, press its icon in Toolbar");
		return;
	}
}

RollDiceAction::~RollDiceAction()
{
}
