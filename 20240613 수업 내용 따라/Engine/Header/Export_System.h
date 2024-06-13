#pragma once

#include "Engine_Define.h"
#include "GraphicDev.h"

BEGIN(Engine)

inline HRESULT		Ready_GraphicDev(HWND hWnd, WINMODE eMode, const _uint& iSizeX, const _uint& iSizeY, Engine::CGraphicDev** ppGraphicDev);
inline void			Render_Begin(D3DXCOLOR Color);
inline void			Render_End();

inline void			Release_System();

#include "Export_System.inl"

END