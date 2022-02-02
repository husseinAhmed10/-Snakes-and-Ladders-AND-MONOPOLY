#pragma once

#include "Action.h"

class InputDiceAction : public Action
{

	int DiceNum;

public:
	InputDiceAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~InputDiceAction();
};

