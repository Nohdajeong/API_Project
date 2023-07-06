#pragma once
#include "IScene.h"
#include "Define.h"
#include "Obj.h"

class CTorielPhase : public IScene
{
public:
	CTorielPhase();
	virtual ~CTorielPhase();

public:
	// IScene을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void	Boss_Phase1();
	void	Boss_Phase2();
	void	Boss_Phase3();

private:
	DWORD		m_dwTime = (DWORD)GetTickCount64();
	DWORD		m_preDeley = (DWORD)GetTickCount64();
	DWORD		m_PostDelay = (DWORD)GetTickCount64();

	int			m_iMonsterPhase = 0;
};

