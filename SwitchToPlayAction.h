#pragma once

#include"Action.h"

class SwitchToPlayAction : public Action
{

public:

	SwitchToPlayAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads SwitchToPlayAction action parameters (startPos, endPos)

	virtual void Execute(); // Switch To Play Mode

	virtual ~SwitchToPlayAction(); // Virtual Destructor

};

