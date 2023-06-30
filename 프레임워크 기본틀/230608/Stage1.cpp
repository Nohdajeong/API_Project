#include "stdafx.h"
#include "Stage1.h"

CStage1::CStage1()
{
}

CStage1::~CStage1()
{
	Release();
}

void CStage1::Initialize() 
{
	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/Map/Ruin.bmp", L"Ruin");
	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayerS1>::Create(WINCX * 0.5f, WINCY * 0.5f));

}

void CStage1::Update()
{
	CObjMgr::Get_Instance()->Update();
}


void CStage1::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
}

void CStage1::Render(HDC hDC)
{
	HDC		hMemDC = CBmpMgr::Get_Instance()->Find_Img(L"Ruin");
	
	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC,	// ���� ���� DC(���������� �׸��� �׸� DC����)
		iScrollX, iScrollY,
		1700, 600,
		hMemDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
		0,					// ��Ʈ���� ����� ���� X,Y��ǥ
		0,
		SRCCOPY);

	CObjMgr::Get_Instance()->Render(hDC);

	TCHAR	szBuff[32] = L"";
	swprintf_s(szBuff, L"TestStage");
	TextOut(hDC, 100, 80, szBuff, lstrlen(szBuff));
}

void CStage1::Release()
{
	CBmpMgr::Destroy_Instance();
	CObjMgr::Get_Instance()->Release();
}

SCENEID CStage1::UpdateScene()
{
	CObj* pPlayer = CObjMgr::Get_Instance()->Get_Player();
	if ((1200.f < pPlayer->Get_Info().fX) && (350.f > pPlayer->Get_Info().fY)) {
			return FLOWEY;
	}

	return RUIN;
}

