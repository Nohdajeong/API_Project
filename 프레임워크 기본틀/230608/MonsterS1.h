#pragma once
#include "ObjS1.h"
class CMonsterS1 : public CObjS1 {

public:
	CMonsterS1();
	virtual ~CMonsterS1();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;
};