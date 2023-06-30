#include "stdafx.h"
#include "NewPlayerOnGround.h"


NewPlayerOnGround::NewPlayerOnGround()
{
}

NewPlayerOnGround::~NewPlayerOnGround()
{

}

NewPlayerState NewPlayerOnGround::OnGroundUpdate(CNewPlayer& _Actor)
{
    if (GetAsyncKeyState('C'))
    {
        _Actor.Set_Jump();
    }

    JUMPSTATE jumpState = _Actor.Jump();
    if (JUMPSTATE::STAND == jumpState)
    {
        if (_Actor.Walk()) {
            return NewPlayerState::Walk;
        }
        return NewPlayerState::Idle;
    }
    else if (JUMPSTATE::JUMP == jumpState)
    {
        return NewPlayerState::Jump;
    }
    else {
        return NewPlayerState::Fall;
    }
}
