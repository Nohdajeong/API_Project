#pragma once
#include "IScene.h"
#include "Define.h"
#include "Obj.h"

class CMonsterItem : public IScene
{
public:
	CMonsterItem();
	virtual ~CMonsterItem();

public:
	// IScene��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	DWORD		m_dwTime = GetTickCount();
};

