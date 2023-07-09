#pragma once
#include "Define.h"
#include "IScene.h"

class Ending : public IScene
{
public:
	Ending() {};
	virtual ~Ending() {};

public:
	virtual void	Initialize(void) override;
	virtual void	Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;

};