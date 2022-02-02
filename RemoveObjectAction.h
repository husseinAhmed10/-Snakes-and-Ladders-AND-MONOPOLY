#pragma once

#include"Action.h"

class RemoveObjectAction : public Action
{
	CellPosition pos;							// position of the object to be removed

public:

	RemoveObjectAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads RemoveObjectAction  parameters (pos)

	virtual void Execute(); // Remove Object


	virtual ~RemoveObjectAction(); // Virtual Destructor

};

