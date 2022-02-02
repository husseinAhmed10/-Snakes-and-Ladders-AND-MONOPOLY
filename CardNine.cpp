#include "CardNine.h"

#include "Ladder.h"
#include "Snake.h"

CardNine::CardNine(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 9; // set the inherited cardNumber data member with the card number (2 here)
}

CardNine::~CardNine(void)
{
}

void CardNine::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	// 2- Read an Integer from the user using the Input class and set the cell to move to parameter with it
	//    Don't forget to first print to a descriptive message to the user 
	pOut->PrintMessage("New CardNine: select cell to move to:");
	CellToMove = pIn->GetCellClicked();
	
	// 3- Clear the status bar
	pOut->ClearStatusBar();
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Card::Apply(pGrid, pPlayer);
	// 2- Move to another cell
	pGrid->UpdatePlayerCell(pPlayer, CellToMove);
	// 3- if the cell to move to have card or ladder or snake
	if (pGrid->GetCopyOfCardInCell(CellToMove) != NULL)
	{
		pGrid->GetCopyOfCardInCell(CellToMove)->Apply(pGrid, pPlayer);
	}
	if (pGrid->GetLadderFromPosition(CellToMove) != NULL)
	{
		pGrid->GetLadderFromPosition(CellToMove)->Apply(pGrid, pPlayer);
	}
	if (pGrid->GetSnakeFromPosition(CellToMove) != NULL)
	{
		pGrid->GetSnakeFromPosition(CellToMove)->Apply(pGrid, pPlayer);
	}

}

 Card* CardNine::CopyParameters(CellPosition position)
{
	Card* pCard = new CardNine(position);
	pCard->SetCardNumber(cardNumber);
	((CardNine*)pCard)->SetPos(CellToMove);
	return pCard;
}

 void CardNine::SetPos(CellPosition P)
 {
	 CellToMove = P;
 }

 void CardNine::Save(ofstream& OutFile, int type)
 {
	 if (type == 2)
	 {
		 Card::Save(OutFile, type);
		 OutFile <<" "<<CellToMove.GetCellNum() <<endl;
	 }
 }