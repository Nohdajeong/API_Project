#include "stdafx.h"
#include "BossAttack.h"

BossAttack::BossAttack()
{
}

BossAttack::~BossAttack()
{
}

void BossAttack::Initialize(Boss& _Actor)
{
	m_preDeley = GetTickCount();
	m_PostDelay = GetTickCount();
}

BossState BossAttack::Update(Boss& _Actor)
{
	_Actor.Attack();
	if (m_preDeley + 2000 < GetTickCount())
	{
		return BossState::Chase;
	}
	return BossState::Attack;
}

void BossAttack::Late_Update(Boss& _Actor)
{
}

void BossAttack::Render(HDC hDC, Boss& _Actor)
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

void BossAttack::Release(Boss& _Actor){
}
