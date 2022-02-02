#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 7; // set the inherited cardNumber data member with the card number 
}

CardSeven::~CardSeven(void)
{
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
	//Ammar msh kateb 7aga fel function

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("New Card Seven: You have another dice roll: ");

	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	

}

 Card* CardSeven::CopyParameters(CellPosition position)
{
	Card* pCard = new CardSeven(position);
	pCard->SetCardNumber(cardNumber);
	return pCard;
}

 void CardSeven::Save(ofstream& OutFile, int type)
 {
	 if (type == 2)
	 {
		 Card::Save(OutFile, type);
		 OutFile << endl;
	 }
 }