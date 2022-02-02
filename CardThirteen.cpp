#include "CardThirteen.h"

CardThirteen::CardThirteen(const CellPosition& pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 13; // set the inherited cardNumber data member with the card number 
	IsOwned = false;
}

CardThirteen::CardThirteen(Grid* pGrid, const CellPosition& pos, int Price, int f)
	:Card(pos)
{
	cardNumber = 13;
	IsAdded = true;
	CardPrice = Price;
	CardFee = f;
}

CardThirteen::~CardThirteen(void)
{
}

void CardThirteen::ReStartCard()
{
	IsOwned = false;
	Owner = NULL;
}

void CardThirteen::ReadCardParameters(Grid* pGrid)
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
			CardThirteen* pThirteen = dynamic_cast<CardThirteen*>(pCard);
			if (pThirteen != NULL)
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
		pOut->PrintMessage("New Card Thirteen: Enter its wallet amount:");
		pGrid->PrintErrorMessage("Please enter the buying price");
		CardPrice = pIn->GetInteger(pOut);
		pGrid->PrintErrorMessage("Please enter the card fees");
		CardFee = pIn->GetInteger(pOut);
		pOut->ClearStatusBar();
	}
	else
	{
		CellPosition cardadded(CellNumOfAnyCard10);
		CardThirteen* pThirteen = dynamic_cast<CardThirteen*>(pGrid->GetCopyOfCardInCell(cardadded));
		CardPrice = pThirteen->CardPrice;
		CardFee = pThirteen->CardFee;
	}



	// 4- Clear the status bar
	pOut->ClearStatusBar();
}

void CardThirteen::EditParametersInCard10(Grid* pGrid)
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
			CardThirteen* pThirteen = dynamic_cast<CardThirteen*>(pCard);
			if (pThirteen != NULL)
			{
				pThirteen->CardPrice = CardPrice;
				pThirteen->CardFee = CardFee;
			}
		}

	}

}

void CardThirteen::Apply(Grid* pGrid, Player* pPlayer)
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
						CardThirteen* C1 = dynamic_cast<CardThirteen*>(C0);
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

Card* CardThirteen::CopyParameters(CellPosition position)
{
	Card* pCard = new CardThirteen(position);
	pCard->SetCardNumber(cardNumber);
	((CardThirteen*)pCard)->CardPrice = CardPrice;
	((CardThirteen*)pCard)->CardFee = CardFee;
	((CardThirteen*)pCard)->IsAdded = true;
	return pCard;
}

void CardThirteen::Save(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << " " << CardPrice << " " << CardFee << endl;
	}
}

void CardThirteen::SpecialSave(ofstream& OutFile, int type)
{
	if (type == 2)
	{
		Card::Save(OutFile, type);
		OutFile << endl;
	}
}

