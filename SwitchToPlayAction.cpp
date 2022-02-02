#include "SwitchToPlayAction.h"

#include"Grid.h"
#include"Output.h"
#include"Input.h"

SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp)
	:Action(pApp)
{
}

void SwitchToPlayAction::ReadActionParameters()
{

}

void SwitchToPlayAction::Execute()
{
	pManager->GetGrid()->GetOutput()->CreatePlayModeToolBar();
}


SwitchToPlayAction::~SwitchToPlayAction()
{

}