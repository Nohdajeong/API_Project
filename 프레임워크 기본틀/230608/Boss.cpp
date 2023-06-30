#include "stdafx.h"
#include "Boss.h"
#include "ObjMgr.h"
#include "BossIdle.h"
#include "BossChase.h"
#include "BossAttack.h"
#include "LineMgr.h"

Boss::Boss()
{
}

Boss::~Boss()
{
}

void Boss::Idle()
{
}

void Boss::Chase()
{
    m_pTarget = CObjMgr::Get_Instance()->Get_Player();
    if (m_pTarget)
    {
        float	fWidth = m_pTarget->Get_Info().fX - m_tInfo.fX;
        float	fHeight = m_pTarget->Get_Info().fY - m_tInfo.fY;

        float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);
        float	fRadian = acosf(fWidth / fDiagonal);

        m_fAngle = fRadian * 180.f / PI;

        if (m_tInfo.fY < m_pTarget->Get_Info().fY)
            m_fAngle *= -1.f;
    }

    m_tInfo.fX += m_fSpeed * cosf(m_fAngle * (PI / 180.f));
    m_tInfo.fY -= m_fSpeed * sinf(m_fAngle * (PI / 180.f));
}

void Boss::Attack()
{
}


void Boss::Initialize(void)
{
    m_tInfo.fCX = 50.f;
    m_tInfo.fCY = 50.f;
    m_fSpeed = 5.f;

	m_States[(int)BossState::Idle] = new BossIdle();
    m_States[(int)BossState::Chase] = new BossChase();
    m_States[(int)BossState::Attack] = new BossAttack();


}

int Boss::Update(void)
{
    if (m_bDead)
        return OBJ_DEAD;

    BossState nowState = m_States[(int)m_eState]->Update(*this);
    if (m_eState != nowState) 
    {
        m_States[(int)m_eState]->Release(*this);

        m_eState = nowState;
        m_States[(int)m_eState]->Initialize(*this);
		m_States[(int)m_eState]->Update(*this);
    }

    
	__super::Update_Rect();
    return OBJ_NOEVENT;
}

void Boss::Late_Update(void)
{
    m_States[(int)m_eState]->Late_Update(*this);
}

void Boss::Render(HDC hDC)
{
    m_States[(int)m_eState]->Render(hDC , *this);
}

void Boss::Release(void)
{

}
