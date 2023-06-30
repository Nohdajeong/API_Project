#include "stdafx.h"
#include "MonsterS4.h"
#include "LineMgr.h"

CMonsterS4::CMonsterS4()
{
}

CMonsterS4::~CMonsterS4()
{
	Release();
}

void CMonsterS4::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_fSpeed = 5.f;
}

int CMonsterS4::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed;

	CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &m_tInfo.fY);

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonsterS4::Late_Update(void)
{
	if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
		m_fSpeed *= -1.f;

}

void CMonsterS4::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CMonsterS4::Release(void)
{
}

