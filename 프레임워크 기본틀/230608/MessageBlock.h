#pragma once
#include "Obj.h"
#include "MyButton.h"
#include "SceneMgr.h"

class CMessageBlock : public CObj
{
public:
	CMessageBlock();
	virtual ~CMessageBlock();

public:
	void	Text_Change(SCENEID eScene);


public:
	// CObjBattle을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	int	m_iDrawID;
	int m_iCount;

	int m_iAttack;
	int m_iDefense;

private:
	TCHAR	szBuff[100] = L"";
	TCHAR	szPlayer[100] = L"";
	DWORD	m_dwTime = GetTickCount();
};

