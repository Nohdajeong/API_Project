#include "stdafx.h"
#include "BossChase.h"

BossChase::BossChase()
{
}

BossChase::~BossChase()
{
}

void BossChase::Initialize(Boss& _Actor)
{
	m_preDeley = GetTickCount();
	m_PostDelay = GetTickCount();
}

BossState BossChase::Update(Boss& _Actor)
{
	
	_Actor.Chase();
	if (m_preDeley + 5000 < GetTickCount()) 
	{
		return BossState::Attack;
	}
	return BossState::Chase;
}

void BossChase::Late_Update(Boss& _Actor)
{
}

void BossChase::Render(HDC hDC, Boss& _Actor)
{
	Rectangle(hDC,
		_Actor.Get_Rect().left,
		_Actor.Get_Rect().top,
		_Actor.Get_Rect().right,
		_Actor.Get_Rect().bottom
	);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"Chase");
	TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top-5, szBuff, lstrlen(szBuff));
}

void BossChase::Release(Boss& _Actor)
{
}
