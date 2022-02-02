#include "SaveGridAction.h"

#include "Grid.h"
#include "Output.h"
#include <fstream>

using namespace std;

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{

}

SaveGridAction::~SaveGridAction()
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter the file name: ");
	FileName = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();

}


// Execute the action
void SaveGridAction::Execute()
{
	
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	ReadActionParameters();
	FileName = FileName + ".txt";
	int SumOfLadders, SumOfSnakes, NumberOfCards;
	SumOfLadders = pGrid->CountLadders();
	SumOfSnakes = pGrid->CountSnakes();
	NumberOfCards = pGrid->CountCards();
	
	ofstream outFile(FileName);
	outFile << SumOfLadders << endl;
	pGrid->SaveAll(outFile, 0);
	outFile << SumOfSnakes << endl;
	pGrid->SaveAll(outFile, 1);
	outFile << NumberOfCards << endl;
	pGrid->SaveAll(outFile, 2);
	outFile.close();

}