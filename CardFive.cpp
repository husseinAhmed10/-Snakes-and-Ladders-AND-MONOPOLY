#include "CardFive.h"

CardFive::CardFive(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 5; // set the inherited cardNumber data member with the card number 
}

CardFive::~CardFive(void)
{
}

void CardFive::ReadCardParameters(Grid* pGrid)
{
	//ammar msh kateb 7aga fel func

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("New CardFive: Move forward the same number of steps that you just rolled ");



	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardFive::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Move forward the same number of steps that you just rolled
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	position.AddCellNum(pPlayer->GetjustRolledDiceNum());
	Card* pCard = pGrid->GetCopyOfCardInCell(position);
	pGrid->UpdatePlayerCell(pPlayer, position);
	if (pCard != NULL)
	{
		pCard->Apply(pGrid, pPlayer);
	}


}

Card* CardFive::CopyParameters(CellPosition position)
{
	Card* pCard = new CardFive(position);
	pCard->SetCardNumber(cardNumber);
	return pCard;
}

void CardFive::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}