#pragma once
#include "Define.h"

template<typename T, typename T2>
class IState
{
public:
	IState() : m_preDeley(GetTickCount()), m_PostDelay(GetTickCount()){};
	virtual ~IState() {};

public:
	virtual void	Initialize(T& _Actor)		PURE;
	virtual T2		Update(T& _Actor)			PURE;
	virtual void	Late_Update(T& _Actor)		PURE;
	virtual void	Render(HDC hDC, T& _Actor)	PURE;
	virtual void	Release(T& _Actor)			PURE;

protected:
	DWORD		m_preDeley;
	DWORD		m_PostDelay;
};