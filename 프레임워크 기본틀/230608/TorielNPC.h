#pragma once
#include "Obj.h"
class CTorielNPC : public CObj {

public:
	CTorielNPC();
	virtual ~CTorielNPC();

public:
	virtual void	Initialize(void) override;
	virtual int		Update(void) override;
	virtual void	Late_Update(void) override;
	virtual void	Render(HDC hDC) override;
	virtual void	Release(void) override;
};