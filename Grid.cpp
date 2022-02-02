#include "Grid.h"

#include "Cell.h"
#include "GameObject.h"
#include "Ladder.h"
#include"Snake.h"
#include "Card.h"
#include "Player.h"
#include"CardTen.h"
#include"CardEleven.h"
#include"CardTweleve.h"
#include"CardThirteen.h"
#include"CardFourteen.h"

Grid::Grid(Input* pIn, Output* pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells - 1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject* pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject* pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if (pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition& pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
	}
}

void Grid::UpdatePlayerCell(Player* player, const CellPosition& newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell* newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input* Grid::GetInput() const
{
	return pIn;
}

Output* Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card* pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card* Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player* Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Ladder* Grid::GetNextLadder(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasLadder() != NULL)
			{
				return CellList[i][j]->HasLadder();
			}

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			if (CellList[i][j]->HasSnake() != NULL)
			{
				return CellList[i][j]->HasSnake();
			}

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found

}

Ladder* Grid::GetLadderFromPosition(const CellPosition position)
{
	if (CellList[position.VCell()][position.HCell()]->HasLadder() != NULL)
	{
		return CellList[position.VCell()][position.HCell()]->HasLadder();
	}

	return NULL;
}

Snake* Grid::GetSnakeFromPosition(const CellPosition position)
{
	if (CellList[position.VCell()][position.HCell()]->HasSnake() != NULL)
	{
		return CellList[position.VCell()][position.HCell()]->HasSnake();
	}

	return NULL;
}

Card* Grid::GetCopyOfCardInCell(CellPosition position)
{
	return CellList[position.VCell()][position.HCell()]->HasCard();
}
GameObject* Grid::GetObjectFromCell(CellPosition position)
{
	int v = position.VCell();
	int h = position.HCell();
	return CellList[v][h]->GetGameObject();
}

// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells - 1; i >= 0; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount - 1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

int Grid::CountLadders()
{
	int counter = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder() != NULL)
			{
				counter++;
			}


		}
	}
	return counter;
}
int Grid::CountSnakes()
{
	int counter = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasSnake() != NULL)
			{
				counter++;
			}


		}
	}
	return counter;
}
int Grid::CountCards()
{
	int counter = 0;
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasCard() != NULL)
			{
				counter++;
			}


		}
	}
	return counter;
}

void Grid::RemoveAll()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->GetGameObject() != NULL)
			{
				RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
			}
		}
	}
}

Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++)
	{
		delete PlayerList[i];
	}
}

bool  Grid::IsOverLapping(GameObject* obj)
{
	Ladder* pLadder = dynamic_cast<Ladder*>(obj);
	if (pLadder != NULL)
	{
		Ladder* ArrOfLadders[9];
		int IndexOfLadders = 0;
		CellPosition Spos = pLadder->GetPosition();
		int Sh = Spos.HCell();
		int Sv = Spos.VCell();
		CellPosition Epos = pLadder->GetEndPosition();
		int Eh = Spos.HCell();
		int Ev = Spos.VCell();

		for (int i = 0;i < NumVerticalCells;i++)
		{
			if (CellList[i][Sh]->HasLadder() != NULL)
			{
				ArrOfLadders[IndexOfLadders++] = CellList[i][Sh]->HasLadder();
			}

			for (int j = 0;j < IndexOfLadders;j++)
			{
				int h1 = (ArrOfLadders[j]->GetPosition()).HCell();
				int v1 = (ArrOfLadders[j]->GetPosition()).VCell();
				int h2 = (ArrOfLadders[j]->GetEndPosition()).HCell();
				int v2 = (ArrOfLadders[j]->GetEndPosition()).VCell();

				if ((v1 <= Sv && v1 >= Ev) || (v2 <= Sv && v2 >= Ev))
				{
					return true;
				}

			}

		}

	}
	else
	{
		Snake* pSnake = dynamic_cast<Snake*> (obj);
		if (pSnake != NULL)
		{
			CellPosition pos = pSnake->GetPosition();
			int h = pos.HCell();
			int v = pos.VCell();
			CellPosition pos2 = pSnake->GetEndPosition();
			int h2 = pos2.HCell();
			int v2 = pos2.VCell();
			Snake* ArrOfSnakes[9];
			int IndexOfArr = 0;
			for (int i = 0; i < NumVerticalCells;i++)
			{
				if (CellList[i][h]->HasSnake() != NULL)
				{
					ArrOfSnakes[IndexOfArr] = CellList[i][h]->HasSnake();
					IndexOfArr++;
				}
				for (int j = 0;j < IndexOfArr;j++)
				{
					int H = (ArrOfSnakes[j]->GetPosition()).HCell();
					int V = (ArrOfSnakes[j]->GetPosition()).VCell();
					int H2 = (ArrOfSnakes[j]->GetEndPosition()).HCell();
					int V2 = (ArrOfSnakes[j]->GetEndPosition()).VCell();
					if ((V >= v && V <= v2) || (V2 >= v && V2 <= v2))
					{
						return true;
					}
				}
			}
		}
		


	}
	return false;
}

void Grid::SaveAll(ofstream& OutFile, int type)
{
	int c10 = 0, c11 = 0, c12 = 0, c13 = 0, c14 = 0;

	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (dynamic_cast<CardTen*>(CellList[i][j]->HasCard()) != NULL && c10 > 0)
			{
				CardTen* a = dynamic_cast<CardTen*>(CellList[i][j]->HasCard());
				a->SpecialSave(OutFile, type);
			}
			else if (dynamic_cast<CardEleven*>(CellList[i][j]->HasCard()) != NULL && c11 > 0)
			{
				CardEleven* a = dynamic_cast<CardEleven*>(CellList[i][j]->HasCard());
				a->SpecialSave(OutFile, type);
			}
			else if (dynamic_cast<CardTweleve*>(CellList[i][j]->HasCard()) != NULL && c12 > 0)
			{
				CardTweleve* a = dynamic_cast<CardTweleve*>(CellList[i][j]->HasCard());
				a->SpecialSave(OutFile, type);
			}
			else if (dynamic_cast<CardThirteen*>(CellList[i][j]->HasCard()) != NULL && c13 > 0)
			{
				CardThirteen* a = dynamic_cast<CardThirteen*>(CellList[i][j]->HasCard());
				a->SpecialSave(OutFile, type);
			}
			else if (dynamic_cast<CardFourteen*>(CellList[i][j]->HasCard()) != NULL && c14 > 0)
			{
				CardFourteen* a = dynamic_cast<CardFourteen*>(CellList[i][j]->HasCard());
				a->SpecialSave(OutFile, type);
			}
			else if (CellList[i][j]->GetGameObject() != NULL)
			{
				CellList[i][j]->GetGameObject()->Save(OutFile, type);
				if (dynamic_cast<CardTen*>(CellList[i][j]->HasCard()) != NULL)
				{
					c10++;
				}
				else if (dynamic_cast<CardEleven*>(CellList[i][j]->HasCard()) != NULL)
				{
					c11++;
				}
				else if (dynamic_cast<CardTweleve*>(CellList[i][j]->HasCard()) != NULL)
				{
					c12++;
				}
				else if (dynamic_cast<CardThirteen*>(CellList[i][j]->HasCard()) != NULL)
				{
					c13++;
				}
				else if (dynamic_cast<CardFourteen*>(CellList[i][j]->HasCard()) != NULL)
				{
					c14++;
				}
			}
		}
	}
}




