#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 8; // set the inherited cardNumber data member with the card number 
	
	for (int i = 0;i < 4;i++)
	{
		playersMoving[i] = true;
	}
}

CardEight::~CardEight(void)
{
}

void CardEight::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("New CardEight: No rolling next turn");
	


	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardEight::convertion(int index)
{
	if (playersMoving[index] == false)
	{
		playersMoving[index] == true;
	}
	else
	{
		playersMoving[index] == false;
	}
}

bool CardEight::GetStatues(int index)
{
	return playersMoving[index];
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- makes the player not rolling next time
	playersMoving[pPlayer->GetPlayerNum()] = false;

}

 Card* CardEight::CopyParameters(CellPosition position)
{
	Card* pCard = new CardEight(position);
	pCard->SetCardNumber(cardNumber);
	return pCard;
}

 void CardEight::Save(ofstream& OutFile, int type)
 {
	 if (type == 2)
	 {
		 Card::Save(OutFile, type);
		 OutFile << endl;
	 }
 }