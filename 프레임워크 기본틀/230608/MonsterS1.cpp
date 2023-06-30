#include "stdafx.h"
#include "MonsterS1.h"
#include "LineMgr.h"

CMonsterS1::CMonsterS1()
{
}

CMonsterS1::~CMonsterS1()
{
	Release();
}

void CMonsterS1::Initialize(void)
{
	m_tInfo.fCX = 50.f;
	m_tInfo.fCY = 50.f;

	m_fSpeed = 5.f;
}

int CMonsterS1::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	m_tInfo.fX += m_fSpeed;

	CLineMgr::Get_Instance()->Collision_Line(m_tInfo.fX, &m_tInfo.fY);

	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonsterS1::Late_Update(void)
{
	if (100 >= m_tRect.left || WINCX - 100 <= m_tRect.right)
		m_fSpeed *= -1.f;

}

void CMonsterS1::Render(HDC hDC)
{
	Rectangle(hDC,
		m_tRect.left,
		m_tRect.top,
		m_tRect.right,
		m_tRect.bottom);
}

void CMonsterS1::Release(void)
{
}

