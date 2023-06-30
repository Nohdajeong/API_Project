#pragma once
#include "ObjS4.h"

class CMonsterS4 : public CObjS4 {

public:
	CMonsterS4();
	virtual ~CMonsterS4();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;
};