#include "stdafx.h"
#include "BossS1_Chase.h"

BossS1_Chase::BossS1_Chase()
{
}

BossS1_Chase::~BossS1_Chase()
{
}

void BossS1_Chase::Initialize(Demeter& _Actor)
{
	m_preDeley = GetTickCount();
	m_PostDelay = GetTickCount();
}

BossState BossS1_Chase::Update(Demeter& _Actor)
{
	_Actor.Chase();
	if (m_preDeley + 5000 < GetTickCount())
	{
		return BossState::Attack;
	}
	return BossState::Chase;
}

void BossS1_Chase::Late_Update(Demeter& _Actor)
{
}

void BossS1_Chase::Render(HDC hDC, Demeter& _Actor)
{
	Rectangle(hDC,
		_Actor.Get_Rect().left,
		_Actor.Get_Rect().top,
		_Actor.Get_Rect().right,
		_Actor.Get_Rect().bottom
	);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"Chase");
	TextOut(hDC, _Actor.Get_Rect().left, _Actor.Get_Rect().top - 5, szBuff, lstrlen(szBuff));
}

void BossS1_Chase::Release(Demeter& _Actor)
{
}
