#include "stdafx.h"
#include "..\Header\MainApp.h"

CMainApp::CMainApp() : m_pGraphicDev(nullptr)
{
}

CMainApp::~CMainApp()
{
}

HRESULT CMainApp::Ready_MainApp()
{
	FAILED_CHECK_RETURN(Engine::Ready_GraphicDev(g_hWnd, MODE_WIN, WINCX, WINCY, &m_pDeviceClass), E_FAIL);
	m_pDeviceClass->AddRef();
	
	m_pGraphicDev = m_pDeviceClass->Get_GraphicDev();
	m_pGraphicDev->AddRef();

	m_pGraphicDev->CreateVertexBuffer(4 * sizeof(VTXCOL), D3DUSAGE_WRITEONLY, FVF_COL, D3DPOOL_MANAGED, &m_pVB, NULL);

	VTXCOL* pVertex;
	m_pVB->Lock(0, 0, (void**) & pVertex, NULL);

	pVertex[0] = { _vec3{-1, 1,0},  D3DCOLOR_XRGB(255, 0, 0) };
	pVertex[1] = { _vec3{ 1.f, 1.f, 0.f},  D3DCOLOR_XRGB(0, 0, 255) };
	pVertex[2] = { _vec3{1.f, -1.f, 0.f},  D3DCOLOR_XRGB(0, 0, 255) };
	pVertex[3] = { _vec3{-1, -1,0},  D3DCOLOR_XRGB(0, 0, 255) };

	m_pVB->Unlock();

	m_pGraphicDev->CreateIndexBuffer(3 * 2 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &m_pIB, NULL);

	WORD* pIndex;
	m_pIB->Lock(0, 0, (void**) &pIndex, NULL);

	pIndex[0] = 1;
	pIndex[1] = 2;
	pIndex[2] = 0;

	pIndex[3] = 0;
	pIndex[4] = 2;
	pIndex[5] = 3;

	m_pIB->Unlock();
	/*

	D3DXMATRIX view;
	D3DXVECTOR3 Position = {0, 0, -5};
	D3DXVECTOR3 Target = { 0, 0, 0 };
	D3DXVECTOR3 Up = {0, 1, 0};

	D3DXMatrixLookAtLH(&view, &Position, &Target, &Up);
	m_pGraphicDev->SetTransform(D3DTS_VIEW, &view);

	D3DXMATRIX proj;
	D3DXMatrixPerspectiveFovLH(&proj, D3DX_PI * 0.5f, WINCX / WINCY, 1, 10.f);
	m_pGraphicDev->SetTransform(D3DTS_PROJECTION, &proj);
	*/
	m_pGraphicDev->SetRenderState(D3DRS_LIGHTING, false);
	m_pGraphicDev->SetRenderState(D3DRS_SHADEMODE, D3DSHADE_GOURAUD);

	return S_OK;
}

int CMainApp::Update_MainApp(const float & fTimeDelta)
{
	D3DXMATRIX matScale;

	D3DXMatrixScaling(&matScale, 5,5,5);
	//m_pGraphicDev->SetTransform(D3DTS_WORLD, &matScale);
	
	
	return 0;
}

void CMainApp::LateUpdate_MainApp()
{
}

void CMainApp::Render_MainApp()
{
	m_pDeviceClass->Render_Begin(D3DXCOLOR(0.f, 0.f, 0.f, 1.f)); //백버퍼 검정으로

	m_pGraphicDev->SetStreamSource(0, m_pVB, 0, sizeof(VTXCOL));
	m_pGraphicDev->SetFVF(FVF_COLOR);
	m_pGraphicDev->SetIndices(m_pIB);
	m_pGraphicDev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);

	m_pDeviceClass->Render_End();
}

CMainApp* CMainApp::Create()
{
	CMainApp*		pMainApp = new CMainApp;

	if (FAILED(pMainApp->Ready_MainApp()))
	{
		delete pMainApp;
		pMainApp = nullptr;
	}

	return pMainApp;
}

void CMainApp::Free()
{
	Engine::Safe_Release(m_pDeviceClass);
	Engine::Safe_Release(m_pGraphicDev);

	Engine::Release_System();
}
