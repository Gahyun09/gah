
HRESULT		Engine::Ready_GraphicDev(HWND hWnd, WINMODE eMode, const _uint& iSizeX, const _uint& iSizeY, Engine::CGraphicDev** ppGraphicDev)
{
	return CGraphicDev::GetInstance()->Ready_GraphicDev(hWnd, eMode, iSizeX, iSizeY, ppGraphicDev);
}
void		Engine::Render_Begin(D3DXCOLOR Color)
{
	CGraphicDev::GetInstance()->Render_Begin(Color);
}
void		Engine::Render_End()
{
	CGraphicDev::GetInstance()->Render_End();
}

void		Engine::Release_System()
{
	CGraphicDev::DestroyInstance();
}