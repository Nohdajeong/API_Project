#pragma once
#include "ObjS2.h"

class CMonsterS2 : public CObjS2 {

public:
	CMonsterS2();
	virtual ~CMonsterS2();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;
};