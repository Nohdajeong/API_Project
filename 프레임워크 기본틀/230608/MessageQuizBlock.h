#pragma once
#include "Obj.h"
#include "MyButton.h"

class CMessageQuizBlock : public CObj
{
public:
	CMessageQuizBlock();
	virtual ~CMessageQuizBlock();

public:
	void	Text_Change();


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

	bool		Search(CObj* _pTarget);

};

