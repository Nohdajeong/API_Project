#pragma once
#include "Define.h"
#include "IScene.h"

class Loading : public IScene
{
public:
	Loading() {};
	virtual ~Loading() {};

public:
	virtual void	Initialize(void)	PURE;
	virtual void	Update(void)		PURE;
	virtual void	Late_Update(void)	PURE;
	virtual void	Render(HDC hDC)		PURE;
	virtual void	Release(void)		PURE;
	virtual SCENEID UpdateScene()		PURE;

protected:
	DWORD		m_dwTime = (DWORD)GetTickCount64();


	
};