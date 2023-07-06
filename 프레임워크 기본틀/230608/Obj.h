#pragma once

#include "Define.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

class CObj abstract
{
public:
	CObj();
	virtual ~CObj();

public:
	RECT			Get_Rect() { return m_tRect; }
	INFO			Get_Info() { return m_tInfo; }
	STATES			Get_States() { return m_tStates; }
	int				Get_Attack() { return m_iAttack; }
	bool			Get_Dead() { return m_bDead; }

	bool			Get_PostAttackDelay()
	{
		if (m_PostAttackDelay + 500 < GetTickCount64()) {
			m_AttackMotion = false;
		}
		return m_PostAttackDelay + 1000 < GetTickCount64();
	}
	bool 			Get_AttackOff() { return m_AttackOff; }
	RENDERID		Get_RenderID() { return m_eRender; }
	float			Get_Speed() { return m_fSpeed; }

	void			Set_Pos(float _fX, float _fY)
	{
		m_tInfo.fX = _fX;
		m_tInfo.fY = _fY;
	}
	void			Set_Dir(DIRECTION eDir) { m_eDir = eDir; }
	void			Set_Dead() { m_bDead = true; }

	void			Set_Hp(int _iHp) { m_tStates.iHp += _iHp; }
	void			Set_Attack(int _iAttack) { m_iAttack = _iAttack; }

	void			Set_Angle(float _fAngle) { m_fAngle = _fAngle; }
	void			Set_Target(CObj* _pTarget) { m_pTarget = _pTarget; }

	void			Set_PosY(float _fY) { m_tInfo.fY += _fY; }
	void			Set_PosX(float _fX) { m_tInfo.fX += _fX; }

	void			Set_FrameKey(TCHAR* pFrameKey) { m_pFrameKey = pFrameKey; }

	void			Set_PostAttackDelay() { m_PostAttackDelay = GetTickCount64(); }

public:
	virtual void		Initialize(void)	PURE;
	virtual int			Update(void)		PURE;
	virtual void		Late_Update(void)	PURE;
	virtual void		Render(HDC hDC)		PURE;
	virtual void		Release(void)		PURE;

protected:
	void		Update_Rect();
	void		Move_Frame();

protected:
	INFO		m_tInfo;
	RECT		m_tRect;
	DIRECTION	m_eDir;
	STATES		m_tStates;
	FRAME		m_tFrame;
	RENDERID	m_eRender;


	CObj*		m_pTarget;

	float		m_fSpeed;
	float		m_fAngle;
	bool		m_bDead;
	int			m_iAttack;

	TCHAR*		m_pFrameKey;

	DWORD		m_PostAttackDelay;
	bool		m_AttackOff;
	bool		m_AttackMotion;

};

