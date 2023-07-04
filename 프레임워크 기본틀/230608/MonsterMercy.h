#pragma once
#include "IScene.h"
#include "Define.h"
#include "Obj.h"

class CMonsterMercy : public IScene
{
public:
	CMonsterMercy();
	virtual ~CMonsterMercy();

public:
	// IScene을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual void Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	DWORD		m_dwTime = GetTickCount();
};

