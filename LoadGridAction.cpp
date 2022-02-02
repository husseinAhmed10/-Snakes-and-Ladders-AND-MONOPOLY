#include "LoadGridAction.h"
#include"Grid.h"
#include<fstream>
#include"CellPosition.h"
#include"Ladder.h"
#include"Snake.h"
#include"Card.h"
#include "CardOne.h"
#include "CardTwo.h"
#include "CardThree.h"
#include"CardFour.h"
#include"CardFive.h"
#include"CardSix.h"
#include"CardSeven.h"
#include"CardEight.h"
#include"CardNine.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTweleve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

using namespace std;


LoadGridAction::LoadGridAction(ApplicationManager* pApp) : Action(pApp)
{

}

LoadGridAction::~LoadGridAction()
{
}

void LoadGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter the file name: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();

}


// Execute the action
void LoadGridAction::Execute()
{
	int n;
	int c10 = 0, c11 = 0, c12 = 0, c13 = 0, c14 = 0;
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pGrid->RemoveAll();
	ReadActionParameters();
	ifstream Input(FileName + ".txt");

	Input >> n;

	for (int i = 0;i < n;i++)
	{
		int cells, celle;
		Input >> cells >> celle;
		CellPosition start(cells), end(celle);
		Ladder* pLadder = new Ladder(start, end);
		pGrid->AddObjectToCell(pLadder);
	}

	Input >> n;

	for (int i = 0;i < n;i++)
	{
		int cells, celle;
		Input >> cells >> celle;
		CellPosition start(cells), end(celle);
		Snake* pSnake = new Snake(start, end);
		pGrid->AddObjectToCell(pSnake);
	}

	Input >> n;

	for (int i = 0;i < n;i++)
	{
		int par, cardnum, pos;
		Card* pCard;
		Input >> cardnum >> pos;
		CellPosition cardposition(pos);

		switch (cardnum)
		{
		case 1:
			pCard = new CardOne(pos);
			Input >> par;
			((CardOne*)pCard)->SetWallet(par);
			pGrid->AddObjectToCell(pCard);
			break;
		case 2:
			pCard = new CardTwo(pos);
			Input >> par;
			((CardTwo*)pCard)->SetWallet(par);
			pGrid->AddObjectToCell(pCard);
			break;
		case 3:
			pCard = new CardThree(pos);
			pGrid->AddObjectToCell(pCard);
			break;
		case 4:
			pCard = new CardThree(pos);
			pGrid->AddObjectToCell(pCard);
			break;
		case 5:
			pCard = new CardThree(pos);
			pGrid->AddObjectToCell(pCard);
			break;
		case 6:
			pCard = new CardThree(pos);
			pGrid->AddObjectToCell(pCard);
			break;
		case 7:
			pCard = new CardThree(pos);
			pGrid->AddObjectToCell(pCard);
			break;
		case 8:
			pCard = new CardThree(pos);
			pGrid->AddObjectToCell(pCard);
			break;
		case 9:
			pCard = new CardThree(pos);
			Input >> par;
			{
				CellPosition N(par);
				((CardNine*)pCard)->SetPos(N);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 10:
			if (c10 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardTen(pGrid, pos, par1, par2);
				c10++;
			}
			else
			{
				pCard = new CardTen(pos);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 11:
			if (c11 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardEleven(pGrid, pos, par1, par2);
				c11++;
			}
			else
			{
				pCard = new CardEleven(pos);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 12:
			if (c12 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardTweleve(pGrid, pos, par1, par2);
				c12++;
			}
			else
			{
				pCard = new CardTweleve(pos);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 13:
			if (c13 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardThirteen(pGrid, pos, par1, par2);
				c13++;
			}
			else
			{
				pCard = new CardThirteen(pos);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;
		case 14:
			if (c14 == 0)
			{
				int par1, par2;
				Input >> par1 >> par2;
				pCard = new CardFourteen(pGrid, pos, par1, par2);
				c14++;
			}
			else
			{
				pCard = new CardFourteen(pos);
				pCard->ReadCardParameters(pGrid);
			}
			pGrid->AddObjectToCell(pCard);
			break;

		}
	}




}