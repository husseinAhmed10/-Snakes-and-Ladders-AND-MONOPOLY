#pragma once

#include "Action.h"
#include "Player.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTweleve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

class NewGameAction : public Action
{

public:

	NewGameAction(ApplicationManager* pApp); // A Constructor

	virtual void ReadActionParameters(); // Reads NewGridAction action parameters (startPos, endPos)

	virtual void Execute(); // makes New game



	virtual ~NewGameAction(); // Virtual Destructor

};

