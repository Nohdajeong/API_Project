#pragma once
#include "State.h"
#include "NewPlayer.h"
#include "NewPlayerOnGround.h"

class NewPlayerIdle : public NewPlayerOnGround
{
public:
	NewPlayerIdle();
	~NewPlayerIdle();

public:
	virtual void				Initialize(CNewPlayer& _Actor) override;
	virtual NewPlayerState		Update(CNewPlayer& _Actor) override;
	virtual void				Late_Update(CNewPlayer& _Actor) override;
	virtual void				Render(HDC hDC, CNewPlayer& _Actor) override;
	virtual void				Release(CNewPlayer& _Actor) override;

};