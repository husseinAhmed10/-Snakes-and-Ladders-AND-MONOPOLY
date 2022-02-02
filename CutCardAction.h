#pragma once

#include "Action.h"
#include"Grid.h"
#include"Card.h"

class CutCardAction : public Action
{

public:
	CutCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CutCardAction action parameters ()

	virtual void Execute(); // cut Card Object of the specific Card Number
							

	virtual ~CutCardAction(); // A Virtual Destructor

};

