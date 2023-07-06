#pragma once
#include "Obj.h"
class CTorielBullet: public CObj
{
public:
	CTorielBullet();
	virtual ~CTorielBullet();

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

private:
	bool		m_bStart;
	POINT		m_tCenter;

	float		m_fRotAngle; // �Ѿ��� ȸ���� ���� ����
	float		m_fRotSpeed; // �Ѿ��� ȸ�� �ӵ�
	float		m_fDistance;

};
