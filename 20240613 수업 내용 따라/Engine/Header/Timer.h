#pragma once

#include "Base.h"
#include "Engine_Define.h"

BEGIN(Engine)

class ENGINE_DLL CTimer : public CBase
{
private :
	explicit CTimer();
	virtual ~CTimer();

public:
	float			Get_TimeDelta() { return m_fTimeDelta; }
	
public:
	HRESULT			Ready_Timer();
	void			Set_TimeDelta();

private:
	LARGE_INTEGER			m_CurTime;
	LARGE_INTEGER			m_OldTime;
	LARGE_INTEGER			m_OriginTime;
	LARGE_INTEGER			m_CpuTick;

	float					m_fTimeDelta;
};

END