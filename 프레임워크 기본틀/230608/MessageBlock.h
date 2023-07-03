#pragma once
#include "ObjBattle.h"
#include "MyButton.h"

class CMessageBlock : public CObjBattle
{
public:
	CMessageBlock();
	virtual ~CMessageBlock();

public:
	void	Text_Change();


public:
	// CObjBattle을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	int	m_iDrawID;

private:
	TCHAR	szBuff[32] = L"";
};

