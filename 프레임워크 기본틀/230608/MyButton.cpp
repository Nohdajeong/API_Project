#include "stdafx.h"
#include "MyButton.h"

CMyButton::CMyButton() : m_iDrawID(0)
{
}

CMyButton::~CMyButton()
{
    Release();
}

void CMyButton::Initialize(void)
{
    m_tInfo.fCX = 145.f;
    m_tInfo.fCY = 55.f;

    m_eRender = UI;
}

int CMyButton::Update(void)
{
    __super::Update_Rect();

    return OBJ_NOEVENT;
}

void CMyButton::Late_Update(void)
{
	POINT	pt{};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON))
		{
			if (!lstrcmp(L"Attack", m_pFrameKey))
				Set_Scene(FIGHT);

			else if (!lstrcmp(L"Act", m_pFrameKey))
				Set_Scene(ACT);

			else if (!lstrcmp(L"Item", m_pFrameKey))
				Set_Scene(ITEM);

			else if (!lstrcmp(L"Mercy", m_pFrameKey))
				Set_Scene(MERCY);
		}

		m_iDrawID = 1;
	}
	else {
		m_iDrawID = 0;
	}

}

void CMyButton::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);

	GdiTransparentBlt(hDC,
		(int)m_tRect.left, // ���� ���� ��ġ X,Y ��ǥ
		(int)m_tRect.top,
		(int)m_tInfo.fCX,	// ���� ���� ����, ���� ����
		(int)m_tInfo.fCY,
		hMemDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
		m_iDrawID * (int)m_tInfo.fCX,					// ��Ʈ���� ����� ���� X,Y��ǥ
		0,
		(int)m_tInfo.fCX,		// ����� ��Ʈ���� ����, ���� ������
		(int)m_tInfo.fCY,
		RGB(195, 134, 255)); // �����ϰ��� �ϴ� ����

}

void CMyButton::Release(void)
{
}