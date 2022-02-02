#pragma once
#include "Card.h"
class CardSix : public Card
{

public:
	CardSix(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card on the passed Player
													 
	virtual Card* CopyParameters(CellPosition position);

	virtual void Save(ofstream& OutFile, int type);
	
	virtual ~CardSix(); // A Virtual Destructor
};

