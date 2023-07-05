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
	// IScene��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	DWORD		m_dwTime = (DWORD)GetTickCount64();
	DWORD		m_preDeley = (DWORD)GetTickCount64();
	DWORD		m_PostDelay = (DWORD)GetTickCount64();

};

