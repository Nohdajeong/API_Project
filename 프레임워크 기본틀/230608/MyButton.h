#pragma once
#include "ObjBattle.h"
class CMyButton : public CObjBattle
{
public:
	CMyButton();
	virtual ~CMyButton();

public:
	// CObjBattle을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	int		m_iDrawID;


};

