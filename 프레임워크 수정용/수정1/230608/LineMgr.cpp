#include "stdafx.h"
#include "LineMgr.h"
#include "KeyMgr.h"

CLineMgr*	CLineMgr::m_pInstance = nullptr;

CLineMgr::CLineMgr()
{
	ZeroMemory(m_tLintPoint, sizeof(m_tLintPoint));
}


CLineMgr::~CLineMgr()
{
	Release();
}

bool CLineMgr::Collision_Line(float& fX, float* pY)
{
	if (m_LineList.empty())
		return false;

	CLine*		pTarget = nullptr;

	for (auto& iter : m_LineList)
	{
		if (iter->Get_Info().tLpoint.fX <= fX &&
			iter->Get_Info().tRpoint.fX > fX)
			pTarget = iter;
	}

	if (!pTarget)
		return false;


	float	x1 = pTarget->Get_Info().tLpoint.fX;
	float	x2 = pTarget->Get_Info().tRpoint.fX;

	float	y1 = pTarget->Get_Info().tLpoint.fY;
	float	y2 = pTarget->Get_Info().tRpoint.fY;

	*pY = ((y2 - y1) / (x2 - x1)) * (fX - x1) + y1;
	
	return true;
}

void CLineMgr::Load_Line()
{
	Release();

	HANDLE		hFile = CreateFile(L"../Data/Line.dat",		// 파일의 경로
		GENERIC_READ,	// 개방 파일의 모드(GENERIC_READ : 읽기 전용 모드)
		NULL, // 공유방식, 파일이 열려있는 상태에서 다른 프로세스가 열려할 때 허가할 것인가, NULL이면 공유하지 않겠다.
		NULL, // 보안속성, NULL인 경우 기본 보안 상태
		OPEN_EXISTING,  // 파일 생성 방식, CREATE_ALWAYS : 파일이 없다면 생성, 파일이 있는 경우 덮어 쓰기, OPEN_EXITING : 파일이 있을 경우에만 열기
		FILE_ATTRIBUTE_NORMAL, // 파일 속성 : FILE_ATTRIBUTE_NORMAL 아무런 속성이 없는 일반적인 파일상태 
		NULL); // 생성될 파일의 속성을 제공할 템플릿 파일, 사용하지 않기 때문에 NULL

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"개방 실패", _T("실패"), MB_OK);
		return;
	}

	DWORD		dwByte = 0;
	LINE		tInfo{};

	while(true)
	{
		ReadFile(hFile, &tInfo, sizeof(LINE), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		m_LineList.push_back(new CLine(tInfo));
	}

	CloseHandle(hFile);
	MessageBox(g_hWnd, L"불러오기 성공", _T("성공"), MB_OK);
}

void CLineMgr::Initialize()
{
	Load_Line();
}

int CLineMgr::Update()
{
	POINT	pt{};
	
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	pt.x -= (int)CScrollMgr::Get_Instance()->Get_ScollX();

	if (CKeyMgr::Get_Instance()->Key_Pressing(VK_LBUTTON))
	{
		if ((!m_tLintPoint[0].fX) && !(m_tLintPoint[0].fY))
		{
			m_tLintPoint[0].fX = float(pt.x);
			m_tLintPoint[0].fY = float(pt.y);
		}
		else
		{
			m_tLintPoint[1].fX = float(pt.x);
			m_tLintPoint[1].fY = float(pt.y);

			LINE	tInfo{ m_tLintPoint[0], m_tLintPoint[1] };
			m_LineList.push_back(new CLine(tInfo));

			m_tLintPoint[0].fX = m_tLintPoint[1].fX;
			m_tLintPoint[0].fY = m_tLintPoint[1].fY;
		}
	}
	
	if (CKeyMgr::Get_Instance()->Key_Down('S'))
		Load_Line();


	return 0;
}

void CLineMgr::Late_Update()
{
}

void CLineMgr::Render(HDC hDC)
{
	for (auto& iter : m_LineList)
		iter->Render(hDC);
}

void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), CDeleteObj());
	m_LineList.clear();
}
