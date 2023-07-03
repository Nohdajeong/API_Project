#pragma once

#include "Line.h"
#include "ScrollMgr.h"

class CLineMgr
{
private:
	CLineMgr();
	~CLineMgr();

public:
	bool		Collision_Line(float& fX, float* pY);
	void		Load_Line();

public:
	void		Initialize();
	int			Update();
	void		Late_Update();
	void		Render(HDC hDC);
	void		Release();
public:
	static CLineMgr*		Get_Instance()
	{
		if (!m_pInstance)
		{
			m_pInstance = new CLineMgr;
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
	list<CLine*>			m_LineList;
	LINEPOINT				m_tLintPoint[2];

	static CLineMgr*		m_pInstance;
};

