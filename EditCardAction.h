#pragma once
#include "Action.h"

class EditCardAction : public Action
{
	// [Action Parameters]
	int cardNumber;            // 1- the card number
	CellPosition cardPosition; // 2- cell position of the card
	Card* pCard;			  //  3- Edited card
	// Note: These parameters should be read in ReadActionParameters()

public:
	EditCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads EditCardAction action parameters (cardNumber, cardPosition)

	virtual void Execute(); // Edit Card Object of the specific Card Number
							// and Reads the Parameters of This Card Number (if any)
							// then Sets this Card Object to GameObject Pointer of its Cell

	virtual ~EditCardAction(); // A Virtual Destructor

};

