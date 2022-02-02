#include "CardThree.h"
#include"Ladder.h"
CardThree::CardThree(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 3; // set the inherited cardNumber data member with the card number 
}

CardThree::~CardThree(void)
{
}

void CardThree::ReadCardParameters(Grid* pGrid)
{
	//ammar msh kateb 7aga hena

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("New CardThree: Move forward to next Ladder if exist");
	


	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Go to next ladder
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Ladder* pLadder = pGrid->GetNextLadder(position);
	if (pLadder == NULL)
	{
		return;
	}
	else
	{
		pGrid->UpdatePlayerCell(pPlayer, pLadder->GetPosition());
		pLadder->Apply(pGrid, pPlayer);
	}

	
}

Card* CardThree::CopyParameters(CellPosition position)
{
	Card* pCard = new CardThree(position);
	pCard->SetCardNumber(cardNumber);
	return pCard;
}

void CardThree::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}

