#include "stdafx.h"
#include "NewPlayerOnAir.h"


NewPlayerOnAir::NewPlayerOnAir()
{
}

NewPlayerOnAir::~NewPlayerOnAir()
{

}

NewPlayerState NewPlayerOnAir::OnAirUpdate(CNewPlayer& _Actor)
{
    _Actor.Move();

    JUMPSTATE jumpState = _Actor.Jump();
    if (JUMPSTATE::JUMP == jumpState) {
        return NewPlayerState::Jump;
    }
    else if (JUMPSTATE::STAND == jumpState)
    {
        return NewPlayerState::Idle;
    }
    else {
        return NewPlayerState::Fall;
    }
}
