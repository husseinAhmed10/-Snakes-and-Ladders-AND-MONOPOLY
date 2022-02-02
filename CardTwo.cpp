#include "CardTwo.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 2; // set the inherited cardNumber data member with the card number (2 here)
}

CardTwo::~CardTwo(void)
{
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("New CardTwo: Enter its wallet amount:");
	walletAmount = pIn->GetInteger(pOut);
	if (walletAmount < 0)
		walletAmount = 0;


	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Increment the wallet of pPlayer by the walletAmount data member of CardOne
	pPlayer = pGrid->GetCurrentPlayer();		//msh katebha Ammar
	pPlayer->SetWallet(pPlayer->GetWallet() + walletAmount);
}

Card* CardTwo::CopyParameters(CellPosition position)
{
	Card* pCard = new CardTwo(position);
	pCard->SetCardNumber(cardNumber);
	((CardTwo*)pCard)->walletAmount = walletAmount;
	return pCard;
}

void CardTwo::SetWallet(int a)
{
	walletAmount = a;
}

void CardTwo::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << " " << walletAmount << endl;
	}
}