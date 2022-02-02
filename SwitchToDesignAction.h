#pragma once

#include"Action.h"

class SwitchToDesignAction : public Action
{

public:

	SwitchToDesignAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads SwitchToDesignAction action parameters (startPos, endPos)

	virtual void Execute(); // Switch To Design Mode
							


	virtual ~SwitchToDesignAction(); // Virtual Destructor

};

