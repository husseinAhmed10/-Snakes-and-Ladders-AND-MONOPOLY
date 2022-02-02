#include "NewGameAction.h"

NewGameAction::NewGameAction(ApplicationManager* pApp) : Action(pApp)
{

}

NewGameAction::~NewGameAction()
{
}

void NewGameAction::ReadActionParameters()
{

}


// Execute the action
void NewGameAction::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	for (int i = 0;i < 4;i++)
	{
		Player* p = pGrid->GetCurrentPlayer();
		p->SetWallet(100);
		p->SetstepCount(0);
		p->SetTurnCount(0);
		CellPosition c(1);
		pGrid->UpdatePlayerCell(p, c);
		pGrid->AdvanceCurrentPlayer();
	}

	Player* p = pGrid->GetCurrentPlayer();
	int pNum = p->GetPlayerNum();

	while (pNum != 0)
	{
		pGrid->AdvanceCurrentPlayer();
		p = pGrid->GetCurrentPlayer();
		pNum = p->GetPlayerNum();

	}
	
	for (int i = 1;i <= 99;i++)
	{
		CellPosition pos(i);
		Card* pCard = pGrid->GetCopyOfCardInCell(pos);
		if (pCard)
		{
			if (dynamic_cast<CardTen*>(pCard))
			{
				CardTen* pCard2 = dynamic_cast<CardTen*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardEleven*>(pCard))
			{
				CardEleven* pCard2 = dynamic_cast<CardEleven*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardTweleve*>(pCard))
			{
				CardTweleve* pCard2 = dynamic_cast<CardTweleve*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardThirteen*>(pCard))
			{
				CardThirteen* pCard2 = dynamic_cast<CardThirteen*>(pCard);
				pCard2->ReStartCard();
			}
			else if (dynamic_cast<CardFourteen*>(pCard))
			{
				CardFourteen* pCard2 = dynamic_cast<CardFourteen*>(pCard);
				pCard2->ReStartCard();
			}
		}
	}
	
	pGrid->SetEndGame(false);
}
