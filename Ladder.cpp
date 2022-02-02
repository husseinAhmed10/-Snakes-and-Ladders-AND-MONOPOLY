#include "Ladder.h"
#include "Card.h"
#include <fstream>

Ladder::Ladder(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
	if (startCellPos.HCell() != endCellPos.HCell())
	{
		return;
	}
	if (startCellPos.VCell() <= endCellPos.VCell())
	{
		return;
	}


}

void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	int x, y;
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetPointClicked(x, y);
	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	pOut->ClearStatusBar();
	Card* pCard = pGrid->GetCopyOfCardInCell(endCellPos);		//should be edited
	if (pCard != NULL)
		pCard->Apply(pGrid, pPlayer);
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

void Ladder::Save(ofstream& OutFile, int type)
{
	if (type == 0)
	{
		GameObject::Save(OutFile, type);
		OutFile << " " << endCellPos.GetCellNum() << endl;
	}
}

Ladder::~Ladder()
{
}
