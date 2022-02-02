#pragma once
#include "Card.h"
#include "Player.h"
class CardThirteen : public Card
{
	bool IsAdded;
	bool IsOwned;
	Player* Owner;
	int CardPrice;
	int CardFee;

public:
	CardThirteen(Grid* pGrid, const CellPosition& pos, int Price, int f);		// A Constructor 

	CardThirteen(const CellPosition& pos);										// A Constructor 

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card

	virtual Card* CopyParameters(CellPosition position);

	virtual void Save(ofstream& OutFile, int type);

	void SpecialSave(ofstream& OutFile, int type);

	void EditParametersInCard10(Grid* pGrid);

	void ReStartCard();

	virtual ~CardThirteen(); // A Virtual Destructor
};

