#include "CardFour.h"
#include"Snake.h"

CardFour::CardFour(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 4; // set the inherited cardNumber data member with the card number 
}

CardFour::~CardFour(void)
{
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	//ammar msh kateb 7aga fel function

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Output Interfaces from the Grid

	Output* pOut = pGrid->GetOutput();
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("New CardFour: Move forward to next Snake if exist");



	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Go to next Snake
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Snake* pSnake = pGrid->GetNextSnake(position);
	if (pSnake == NULL)
	{
		return;
	}
	else
	{
		pGrid->UpdatePlayerCell(pPlayer, pSnake->GetPosition());
		pSnake->Apply(pGrid, pPlayer);
	}


}

 Card* CardFour::CopyParameters(CellPosition position)
{
	Card* pCard = new CardFour(position);
	pCard->SetCardNumber(cardNumber);
	return pCard;
}

 void CardFour::Save(ofstream& OutFile, int type)
 {
	 if (type == 2)
	 {
		 Card::Save(OutFile, type);
		 OutFile << endl;
	 }
 }