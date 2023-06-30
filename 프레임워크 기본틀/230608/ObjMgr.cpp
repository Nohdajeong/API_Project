#include "stdafx.h"
#include "ObjMgr.h"
#include "CollisionMgr.h"

CObjMgr* CObjMgr::m_pInstance = nullptr;

CObjMgr::CObjMgr()
{
}


CObjMgr::~CObjMgr()
{
	Release();
}

CObj* CObjMgr::Get_Target(OBJID eID, CObj* pInstance)
{
	if (m_ObjList[eID].empty())
		return nullptr;

	CObj* pTarget = nullptr;
	float	fDistance = 0.f;

	for (auto& iter : m_ObjList[eID])
	{
		if (iter->Get_Dead())
			continue;

		float	fWidth = iter->Get_Info().fX - pInstance->Get_Info().fX;
		float	fHeight = iter->Get_Info().fY - pInstance->Get_Info().fY;

		float	fDiagonal = sqrtf(fWidth * fWidth + fHeight * fHeight);

		// 최초의 경우
		if ((!pTarget) || (fDistance > fDiagonal))
		{
			pTarget = iter;
			fDistance = fDiagonal;
		}
	}

	return pTarget;
}

void CObjMgr::Add_Object(OBJID eID, CObj* pInstance)
{
	if (OBJID_END <= eID || nullptr == pInstance)
		return;

	m_ObjList[eID].push_back(pInstance);
}

int CObjMgr::Update()
{
	for (size_t i = 0; i < OBJID_END; ++i)
	{
		for (auto iter = m_ObjList[i].begin();
			iter != m_ObjList[i].end(); )
		{
			int iResult = (*iter)->Update();

			if (OBJ_DEAD == iResult)
			{
				Safe_Delete<CObj*>(*iter);
				iter = m_ObjList[i].erase(iter);
			}
			else
				++iter;
		}
	}

	return 0;
}

void CObjMgr::Late_Update()
{
	for (size_t i = 0; i < OBJID_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
			iter->Late_Update();
	}

	CCollisionMgr::Collision_RectEx(m_ObjList[MONSTER], m_ObjList[PLAYER]);
	CCollisionMgr::Collision_Rect(m_ObjList[MONSTER], m_ObjList[BULLET]);
	//CCollisionMgr::Collision_Sphere(m_ObjList[MOUSE], m_ObjList[MONSTER]);
}

void CObjMgr::Render(HDC hDC)
{

	for (size_t i = 0; i < OBJID_END; ++i)
	{
		for (auto& iter : m_ObjList[i])
			iter->Render(hDC);
	}

}

void CObjMgr::Release()
{
	for (size_t i = 0; i < OBJID_END; ++i)
	{
		for_each(m_ObjList[i].begin(), m_ObjList[i].end(), Safe_Delete<CObj*>);
		m_ObjList[i].clear();
	}
}
