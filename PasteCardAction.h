#pragma once

#include "Action.h"
#include"Grid.h"
#include"Card.h"

class PasteCardAction : public Action
{

public:
	PasteCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads PasteCardAction action parameters ()

	virtual void Execute(); // Paste Card Object of the specific Card Number


	virtual ~PasteCardAction(); // A Virtual Destructor

};

