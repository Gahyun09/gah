#pragma once
#include "Timer.h"

BEGIN(Engine)

class CTimerMgr : public CBase
{
private:
	explicit CTimerMgr();
	virtual ~CTimerMgr();

public:
	HRESULT			Ready_Timer();

private:
	CTimer*			Find_Timer(const TCHAR* pTimerTag);

public:
	static CTimer*		Create();

private:
	virtual void		Free();
};

END