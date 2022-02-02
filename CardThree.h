#pragma once
#include "Card.h"
class CardThree : public Card
{
	

public:
	CardThree(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member
	virtual Card* CopyParameters(CellPosition position);

	virtual void Save(ofstream& OutFile, int type);
	
	virtual ~CardThree(); // A Virtual Destructor
};

