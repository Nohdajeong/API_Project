#pragma once
#include "Define.h"
#include "IScene.h"

class Intro : public IScene
{
public:
	Intro() {};
	virtual ~Intro() {};

public:
	virtual void	Initialize(void) override;
	virtual void	Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;

};