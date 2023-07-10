#pragma once
#include "Obj.h"
#include "SceneMgr.h"

class CTorielDieMention : public CObj
{
public:
	CTorielDieMention();
	virtual ~CTorielDieMention();

public:
	// CObjBattle��(��) ���� ��ӵ�
	virtual void Initialize(void) override;
	virtual int Update(void) override;
	virtual void Late_Update(void) override;
	virtual void Render(HDC hDC) override;
	virtual void Release(void) override;

public:
	int	m_iDrawID;
	int m_iCount;

	int m_iAttack;
	int m_iDefense;

private:
	TCHAR	szBuff[100] = L"";
	TCHAR	szBuff2[100] = L"";
	TCHAR	szBuff3[100] = L"";
	DWORD	m_dwTime = (DWORD) GetTickCount64();
};

