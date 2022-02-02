#pragma once
#include "Card.h"
#include "Player.h"
class CardTweleve : public Card
{
	bool IsAdded;
	bool IsOwned;
	Player* Owner;
	int CardPrice;
	int CardFee;

public:
	CardTweleve(Grid* pGrid, const CellPosition& pos, int Price, int f);		// A Constructor 

	CardTweleve(const CellPosition& pos);										// A Constructor 

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of Card

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of Card

	virtual Card* CopyParameters(CellPosition position);

	virtual void Save(ofstream& OutFile, int type);

	void SpecialSave(ofstream& OutFile, int type);

	void EditParametersInCard10(Grid* pGrid);

	void ReStartCard();

	virtual ~CardTweleve(); // A Virtual Destructor
};

