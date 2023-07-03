#include "stdafx.h"
#include "Monster.h"
#include "ObjMgr.h"
#include "BmpMgr.h"
#include "ScrollMgr.h"

CMonster::CMonster()
{
	ZeroMemory(m_tPoint, sizeof(m_tPoint));
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(void)
{
	m_tInfo.fX = 200.f;
	m_tInfo.fY = 200.f;
	m_tInfo.fCX = 300.f;
	m_tInfo.fCY = 300.f;

	m_fSpeed = 5.f;
	m_fAngle = 0.f;

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Monster.bmp", L"Monster");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Plg.bmp", L"Plg");
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Monster/Reset.bmp", L"Reset");

	m_pFrameKey = L"Monster";

	m_eRender = GAMEOBJECT;
}

int CMonster::Update(void)
{
	if (m_bDead)
		return OBJ_DEAD;

	if (GetAsyncKeyState('A'))
		m_fAngle += 3.f;

	
	__super::Update_Rect();

	return OBJ_NOEVENT;
}

void CMonster::Late_Update(void)
{
	float		fDiagonal = sqrtf((m_tInfo.fCX / 2.f) *(m_tInfo.fCX / 2.f) + (m_tInfo.fCY / 2.f) * (m_tInfo.fCY / 2.f));

	// �� ���
	m_tPoint[0].x = LONG((m_tInfo.fCX / 2.f) + fDiagonal * cosf((m_fAngle + 135.f) * (PI / 180.f)));
	m_tPoint[0].y = LONG((m_tInfo.fCY / 2.f) - fDiagonal * sinf((m_fAngle + 135.f) * (PI / 180.f)));

	// �� ���
	m_tPoint[1].x = LONG((m_tInfo.fCX / 2.f) + fDiagonal * cosf((m_fAngle + 45.f) * (PI / 180.f)));
	m_tPoint[1].y = LONG((m_tInfo.fCY / 2.f) - fDiagonal * sinf((m_fAngle + 45.f) * (PI / 180.f)));

	// �� �ϴ�
	m_tPoint[2].x = LONG((m_tInfo.fCX / 2.f) + fDiagonal * cosf((m_fAngle + 225.f) * (PI / 180.f)));
	m_tPoint[2].y = LONG((m_tInfo.fCY / 2.f) - fDiagonal * sinf((m_fAngle + 225.f) * (PI / 180.f)));

}

void CMonster::Render(HDC hDC)
{
	int		iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int		iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(m_pFrameKey);
	HDC		hPlgDC = CBmpMgr::Get_Instance()->Find_Img(L"Plg");
	HDC		hResetDC = CBmpMgr::Get_Instance()->Find_Img(L"Reset");

	PlgBlt(hPlgDC,	// ȸ�� ��ų �̹����� ��� �׸� ���ΰ�
			m_tPoint, // �׸��� �׸� �簢���� ��ǥ point ���� 3��
			hMemDC,  // ��� �ִ� �̹����� ȸ���Ͽ� �׸� ���ΰ�
			0,  // �׸��� �׸� �̹����� x,y ���� ��ǥ
			0, 
			(int)m_tInfo.fCX, // �׸� �̹����� ����, ���� ����
			(int)m_tInfo.fCY, 
			NULL, NULL, NULL);	// ����
	

	GdiTransparentBlt(hDC,
		(int)m_tRect.left + iScrollX,
		(int)m_tRect.top + iScrollY,
		(int)m_tInfo.fCX,	
		(int)m_tInfo.fCY,
		hPlgDC,
		0,				
		0,
		(int)m_tInfo.fCX,
		(int)m_tInfo.fCY,
		RGB(255, 255, 255)); 

	BitBlt(hPlgDC, 0, 0, int(m_tInfo.fCX), int(m_tInfo.fCY), hResetDC, 0, 0, SRCCOPY);

}

void CMonster::Release(void)
{
}
