#pragma once
#include "Card.h"
class CardNine : public Card
{
	// CardNine Parameters:
	CellPosition CellToMove; // cell to move to

public:
	CardNine(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardNine which is: cell to move to

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player
													  

	virtual Card* CopyParameters(CellPosition position);
	void SetPos(CellPosition P);
	
	virtual void Save(ofstream& OutFile, int type);

	virtual ~CardNine(); // A Virtual Destructor
};

