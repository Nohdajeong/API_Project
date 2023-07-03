#pragma once
#include "IScene.h"
#include "DefineS2.h"
#include "ObjBattle.h"

class CBattle : public IScene
{
public:
	CBattle();
	virtual ~CBattle();

public:
	// IScene��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;
	virtual SCENEID UpdateScene() override;

private:
	DWORD		m_dwTime = GetTickCount();
};

