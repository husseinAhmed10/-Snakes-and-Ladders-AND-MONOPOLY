#include "CardTweleve.h"

CardTweleve::CardTweleve(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 12; // set the inherited cardNumber data member with the card number 
	IsOwned = false;
}

CardTweleve::CardTweleve(Grid* pGrid, const CellPosition& pos, int Price, int f)
	:Card(pos)
{
	cardNumber = 12;
	IsAdded = true;
	CardPrice = Price;
	CardFee = f;
}

CardTweleve::~CardTweleve(void)
{
}

void CardTweleve::ReStartCard()
{
	IsOwned = false;
	Owner = NULL;
}

void CardTweleve::ReadCardParameters(Grid* pGrid)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid
	Input* pIn = pGrid->GetInput();
	int CellNumOfAnyCard10;
	Output* pOut = pGrid->GetOutput();
	IsAdded = false;

	// 2- Check if there exist another card in the grid with the initialized parameters

	for (int i = 1;i <= 99;i++)
	{
		CellPosition pC(i);
		Card* pCard = pGrid->GetCopyOfCardInCell(pC);
		if (pCard != NULL)
		{
			CardTweleve* pTweleve = dynamic_cast<CardTweleve*>(pCard);
			if (pTweleve != NULL)
			{
				IsAdded = true;
				CellNumOfAnyCard10 = i;
				break;
			}
		}

	}

	// 3-if there doesn't exist another card in the grid with the initialized parameters
	if (IsAdded == false)
	{
		pOut->PrintMessage("New Card Tweleve: Enter its wallet amount:");
		pGrid->PrintErrorMessage("Please enter the buying price");
		CardPrice = pIn->GetInteger(pOut);
		pGrid->PrintErrorMessage("Please enter the card fees");
		CardFee = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}
	else
	{
		CellPosition cardadded(CellNumOfAnyCard10);
		CardTweleve* pTweleve = dynamic_cast<CardTweleve*>(pGrid->GetCopyOfCardInCell(cardadded));
		CardPrice = pTweleve->CardPrice;
		CardFee = pTweleve->CardFee;
	}



	// 4- Clear the status bar
	pOut->ClearStatusBar();
}

void CardTweleve::EditParametersInCard10(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("Enter the card price: ");
	CardPrice = pIn->GetInteger(pOut);
	pOut->PrintMessage("Enter the card Fee: ");
	CardFee = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();

	for (int i = 1;i <= 99;i++)
	{
		CellPosition c(i);
		Card* pCard = pGrid->GetCopyOfCardInCell(c);

		if (pCard != NULL)
		{
			CardTweleve* pTweleve = dynamic_cast<CardTweleve*>(pCard);
			if (pTweleve != NULL)
			{
				pTweleve->CardPrice = CardPrice;
				pTweleve->CardFee = CardFee;
			}
		}

	}

}

void CardTweleve::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Card::Apply(pGrid, pPlayer);
	// 2- check if this card owned or not
	if (IsOwned == false)
	{
		pOut->PrintMessage("press y then enter if you want to buy this card");
		string ans = pIn->GetSrting(pOut);
		pOut->ClearStatusBar();
		if (ans == "y" || ans == "Y" || ans == "yes" || ans == "Yes")
		{
			if ((pPlayer->GetWallet() - CardPrice) < 0)
			{
				return;
			}
			else
			{
				pPlayer->SetWallet(pPlayer->GetWallet() - CardPrice);
				IsOwned = true;
				Owner = pPlayer;
				for (int i = 1;i <= 99;i++)
				{
					CellPosition pos3(i);
					Card* C0 = pGrid->GetCopyOfCardInCell(pos3);
					if (C0)
					{
						CardTweleve* C1 = dynamic_cast<CardTweleve*>(C0);
						if (C1)
						{
							C1->IsOwned = true;
							C1->Owner = Owner;
						}
					}
				}

			}
		}


	}
	else
	{
		if (pPlayer->GetPlayerNum() != Owner->GetPlayerNum())
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - CardFee);
			Owner->SetWallet(Owner->GetWallet() + CardFee);
		}
	}





}

Card* CardTweleve::CopyParameters(CellPosition position)
{
	Card* pCard = new CardTweleve(position);
	pCard->SetCardNumber(cardNumber);
	((CardTweleve*)pCard)->CardPrice = CardPrice;
	((CardTweleve*)pCard)->CardFee = CardFee;
	((CardTweleve*)pCard)->IsAdded = true;
	return pCard;
}

void CardTweleve::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << " " << CardPrice << " " << CardFee << endl;
	}
}

void CardTweleve::SpecialSave(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}
