#include "stdafx.h"
#include "MessageBlock.h"

CMessageBlock::CMessageBlock() : m_iDrawID(0)
{
}

CMessageBlock::~CMessageBlock()
{
    Release();
}

void CMessageBlock::Text_Change()
{
	switch (m_eScene)
	{
	case IDLE:
		swprintf_s(szBuff, L"* 룩스가 나타났다!");
		break;

	case FIGHT:
		swprintf_s(szBuff, L"* 공격!");
		break;

	case ACT:
		swprintf_s(szBuff, L"* 행동!");
		break;

	case ITEM:
		swprintf_s(szBuff, L"* 아이템!");
		break;

	case MERCY:
		swprintf_s(szBuff, L"* 자비!");
		break;
		
	default:		
		swprintf_s(szBuff, L"* 이건 디폴트!");
		break;


	}
}

void CMessageBlock::Initialize(void)
{
    m_tInfo.fCX = 700.f;
    m_tInfo.fCY = 200.f;

	m_tInfo.fX = 400.f;
	m_tInfo.fY = 400.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Message.bmp", L"Message");

    m_eRender = UI;

}

int CMessageBlock::Update(void)
{
	Text_Change();
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMessageBlock::Late_Update(void)
{
	//if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
	//{
	//	if (!lstrcmp(L"Attack", m_pFrameKey))
	//		swprintf_s(szBuff, L"* 공격");

	//	else if (!lstrcmp(L"Act", m_pFrameKey))
	//		swprintf_s(szBuff, L"* 행동");

	//	else if (!lstrcmp(L"Item", m_pFrameKey))
	//		swprintf_s(szBuff, L"* 아이템");

	//	else if (!lstrcmp(L"Mercy", m_pFrameKey))
	//		swprintf_s(szBuff, L"* 자비");

	//	else if (!lstrcmp(L"Idle", m_pFrameKey))
	//		swprintf_s(szBuff, L"* 시작");
	//}

}

void CMessageBlock::Render(HDC hDC)
{
	AddFontResourceA("Neo둥근모.ttf");

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Message");

	GdiTransparentBlt(hDC,
		(int)m_tRect.left, // 복사 받을 위치 X,Y 좌표
		(int)m_tRect.top,
		(int)m_tInfo.fCX,	// 복사 받을 가로, 세로 길이
		(int)m_tInfo.fCY,
		hMemDC,			// 비트맵 이미지를 담고 있는 DC
		m_iDrawID * (int)m_tInfo.fCX,					// 비트맵을 출력할 시작 X,Y좌표
		0,
		(int)m_tInfo.fCX,		// 출력할 비트맵의 가로, 세로 사이즈
		(int)m_tInfo.fCY,
		RGB(195, 134, 255)); // 제거하고자 하는 색상

	SetBkMode(hDC, 1);
	SetTextColor(hDC, RGB(255, 255, 255));
	HFONT	hFont, oldFont;

	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, VARIABLE_PITCH || FF_ROMAN, TEXT("Neo둥근모"));
	oldFont = (HFONT)SelectObject(hDC, hFont);
	TextOut(hDC, (float)m_tRect.left + 40.f,(float) m_tInfo.fY - 50.f, szBuff, lstrlen(szBuff));
}

void CMessageBlock::Release(void)
{
}