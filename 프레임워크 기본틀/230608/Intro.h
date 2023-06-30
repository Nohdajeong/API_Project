#pragma once
#include "Loading.h"
class Intro : public Loading
{
public:
	virtual void	Initialize(void) override;
	virtual void	Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;
	virtual SCENEID UpdateScene() override;

};