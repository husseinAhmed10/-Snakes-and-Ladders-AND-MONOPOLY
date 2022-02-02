#pragma once

#include "Action.h"
#include"Grid.h"
#include"Card.h"

class CopyCardAction : public Action
{

public:
	CopyCardAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads CopyCardAction action parameters ()

	virtual void Execute(); // Copy Card Object of the specific Card Number
							

	virtual ~CopyCardAction(); // A Virtual Destructor

};

