#pragma once
#include "State.h"
#include "NewPlayer.h"

class NewPlayerOnGround : public IState<CNewPlayer, NewPlayerState>
{
public:
	NewPlayerOnGround();
	virtual ~NewPlayerOnGround();

protected:
	virtual NewPlayerState		OnGroundUpdate(CNewPlayer& _Actor);

};