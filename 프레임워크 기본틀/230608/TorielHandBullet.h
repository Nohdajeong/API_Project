#pragma once
#include "Obj.h"
class CTorielHandBullet: public CObj
{
public:
	CTorielHandBullet();
	virtual ~CTorielHandBullet();

public:
	// CObj��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

private:
	DWORD		m_dwTime;
	int			m_iTime;
	int			m_iDrawID;

private:
	CObj*		Create_Bullet();

};
