#pragma once
#include "Card.h"
class CardEight : public Card
{
	bool playersMoving[4];

public:
	CardEight(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card eight 

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card eight 

	void convertion(int index);						

	bool GetStatues(int index);

	virtual Card* CopyParameters(CellPosition position);

	virtual void Save(ofstream& OutFile, int type);

	virtual ~CardEight(); // A Virtual Destructor
};

