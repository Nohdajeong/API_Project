#include "stdafx.h"
#include "BossS1_Attack.h"

BossS1_Attack::BossS1_Attack()
{
}

BossS1_Attack::~BossS1_Attack()
{
}

void BossS1_Attack::Initialize(Demeter& _Actor)
{
    m_preDeley = GetTickCount();
    m_PostDelay = GetTickCount();
}

BossState BossS1_Attack::Update(Demeter& _Actor)
{
	_Actor.Attack();
	if (m_preDeley + 2000 < GetTickCount())
	{
		return BossState::Chase;
	}
	return BossState::Attack;
}

void BossS1_Attack::Late_Update(Demeter& _Actor)
{
}

void BossS1_Attack::Render(HDC hDC, Demeter& _Actor)
{
	Rectangle(hDC,
		_Actor.Get_Rect().left,
		_Actor.Get_Rect().top,
		_Actor.Get_Rect().right,
		_Actor.Get_Rect().bottom
	);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"Attack");
	TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top - 5, szBuff, lstrlen(szBuff));
}

void BossS1_Attack::Release(Demeter& _Actor)
{
}
