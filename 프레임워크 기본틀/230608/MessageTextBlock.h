#pragma once
#include "Obj.h"
#include "MyButton.h"
#include "SceneMgr.h"

class CMessageTextBlock : public CObj
{
public:
	CMessageTextBlock();
	virtual ~CMessageTextBlock();

public:
	void	Text_Change(SCENEID eScene);


public:
	// CObjBattle을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	TCHAR	szBuff[100] = L"";
	TCHAR	szPlayer[100] = L"";
	DWORD	m_dwTime = (DWORD)GetTickCount64();
};

