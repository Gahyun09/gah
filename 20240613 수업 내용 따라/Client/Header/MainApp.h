#pragma once

#include "../../Base/Base.h"


#include "../../Engine/Header/Engine_Define.h"
#include "../../Engine/Header/GraphicDev.h"
#include "../../Engine/Header/Export_Function.h"


class CMainApp : public CBase
{
private:		// »ý¼ºÀÚ
	explicit CMainApp();
	virtual ~CMainApp();

public:
	HRESULT		Ready_MainApp();
	int			Update_MainApp(const float& fTimeDelta);
	void		LateUpdate_MainApp();
	void		Render_MainApp();

private:
	Engine::CGraphicDev*		m_pDeviceClass;
	LPDIRECT3DDEVICE9			m_pGraphicDev;


public:
	static	CMainApp* Create();
private:
	virtual	void			Free();

};

