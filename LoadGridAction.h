#pragma once

#include "Action.h"
#include<fstream>
#include<string>

class LoadGridAction : public Action
{

	string FileName;

public:

	LoadGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads LoadGridAction action parameters (startPos, endPos)

	virtual void Execute(); // Load the grid



	virtual ~LoadGridAction(); // Virtual Destructor

};

