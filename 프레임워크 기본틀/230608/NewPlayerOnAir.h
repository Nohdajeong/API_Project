#pragma once
#include "State.h"
#include "NewPlayer.h"

class NewPlayerOnAir : public IState<CNewPlayer, NewPlayerState>
{
public:
	NewPlayerOnAir();
	virtual ~NewPlayerOnAir();

protected:
	virtual NewPlayerState		OnAirUpdate(CNewPlayer& _Actor);

};