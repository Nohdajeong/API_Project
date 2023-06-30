#pragma once

#include "Define.h"
#include "Obj.h"

class CObjMgr
{
private:
	CObjMgr();
	~CObjMgr();

public:
	CObj* Get_Player() { return m_ObjList[PLAYER].front(); }
	list<CObj*>	Get_Objects(OBJID eId) { return m_ObjList[eId]; }
	CObj* Get_Target(OBJID eID, CObj* pInstance);

public:
	void		Add_Object(OBJID eID, CObj* pInstance);
	int			Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();

	

public:
	static CObjMgr* Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CObjMgr;
		}

		return m_pInstance;
	}
	static void		Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	list<CObj*>	m_ObjList[OBJID_END];
	list<CObj*>	m_ObjTemp[OBJID_END];

	static CObjMgr* m_pInstance;
};
