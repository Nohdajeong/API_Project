#include "stdafx.h"
#include "Stage.h"
#include "ObjMgr.h"
#include "LineMgr.h"
#include "BmpMgr.h"

#include "AbstractFactory.h"
#include "Player.h"
#include "TileMgr.h"

CStage::CStage()
{
}

CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	CObjMgr::Get_Instance()->Add_Object(PLAYER, CAbstractFactory<CPlayer>::Create());
	CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CMonster>::Create());
	//CLineMgr::Get_Instance()->Initialize();

	//CTileMgr::Get_Instance()->Load_Tile();
	//CTileMgr::Get_Instance()->Initialize();

	CBmpMgr::Get_Instance()->Insert_Bmp(L"../Image/Ground.bmp", L"Ground");
}

void CStage::Update()
{
	CObjMgr::Get_Instance()->Update();
	//CLineMgr::Get_Instance()->Update();

	//CTileMgr::Get_Instance()->Update();
}

void CStage::Late_Update()
{
	CObjMgr::Get_Instance()->Late_Update();
	//CTileMgr::Get_Instance()->Late_Update();
}

void CStage::Render(HDC hDC)
{
	HDC		hGoundDC = CBmpMgr::Get_Instance()->Find_Img(L"Ground");

	int	iScrollX = (int)CScrollMgr::Get_Instance()->Get_ScollX();
	int	iScrollY = (int)CScrollMgr::Get_Instance()->Get_ScollY();

	BitBlt(hDC,	// ���� ���� DC(���������� �׸��� �׸� DC����)
	iScrollX, iScrollY, 1920, 1280,
	hGoundDC,			// ��Ʈ�� �̹����� ��� �ִ� DC
	0,					// ��Ʈ���� ����� ���� X,Y��ǥ
	0,
	SRCCOPY);

	//CTileMgr::Get_Instance()->Render(hDC);

	CObjMgr::Get_Instance()->Render(hDC);
	
	//CLineMgr::Get_Instance()->Render(hDC);
}

void CStage::Release()
{
	
}
