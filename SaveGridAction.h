#pragma once

#include "Action.h"
#include<fstream>
#include<string>

class SaveGridAction : public Action
{

	string FileName;

public:

	SaveGridAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads LoadGridAction action parameters (startPos, endPos)

	virtual void Execute(); // Load the grid



	virtual ~SaveGridAction(); // Virtual Destructor

};

