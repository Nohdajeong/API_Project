#pragma once
#include "Obj.h"
class CPlayerBattle : public CObj
{
public:
	CPlayerBattle();
	virtual ~CPlayerBattle();

public:
	// CObj을(를) 통해 상속됨
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	void	Key_Input(void);
};

