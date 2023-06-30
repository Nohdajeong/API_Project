#include "stdafx.h"
#include "Intro.h"

void Intro::Initialize(void)
{
	m_dwTime = GetTickCount();
}

void Intro::Update(void)
{
}

void Intro::Late_Update(void)
{
}

void Intro::Render(HDC hDC)
{
	Rectangle(hDC, 0, 0, WINCX, WINCY);
	Rectangle(hDC, 100, 100, WINCX - 100, WINCY - 100);

	{
		TCHAR	szBuff[32] = L"";
		swprintf_s(szBuff, L"TEAM 1");
		TextOut(hDC, WINCX / 2 - 20, WINCY / 2 - 50, szBuff, lstrlen(szBuff));
	}

	{
		TCHAR	szBuff[32] = L"";
		swprintf_s(szBuff, L"³ë´ÙÁ¤, ÀÌ¼ºÈñ, Á¤½Â¿ë, ÇÑ¸íºó");
		TextOut(hDC, WINCX / 2 - 100, WINCY / 2 + 30, szBuff, lstrlen(szBuff));
	}

}

void Intro::Release(void)
{
}

SCENEID Intro::UpdateScene()
{
	if (GetAsyncKeyState(VK_SPACE))
	{
		return RUIN;
	}

	return INTRO;
}
