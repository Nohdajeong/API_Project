#include "stdafx.h"
#include "MonsterMercy.h"
#include "Look.h"
#include "MyButton.h"
#include "MessageBlock.h"

CMonsterMercy::CMonsterMercy()
{
}

CMonsterMercy::~CMonsterMercy()
{
    Release();
}

void CMonsterMercy::Initialize(void)
{
    CBmpMgr::Get_Instance()->Insert_Bmp(L"../Resource/UI/Back_Monster.bmp", L"Back_Monster");

    CObjMgr::Get_Instance()->Add_Object(MONSTER, CAbstractFactory<CLook>::Create(300.f, 250.f));
    CObjMgr::Get_Instance()->Add_Object(MESSAGEBOX, CAbstractFactory<CMessageBlock>::Create(400.f, 400.f));
}

void CMonsterMercy::Update(void)
{
    CObjMgr::Get_Instance()->Update();
}

void CMonsterMercy::Late_Update(void)
{
    CObjMgr::Get_Instance()->Late_Update();

    if (m_dwTime + 5000 < GetTickCount())
        CSceneMgr::Get_Instance()->Scene_Change(RUIN);

}

void CMonsterMercy::Render(HDC hDC)
{
    CObjMgr::Get_Instance()->Render(hDC);

}

void CMonsterMercy::Release(void)
{
    CObjMgr::Get_Instance()->Destroy_Instance();
}
