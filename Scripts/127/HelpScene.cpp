#include "DXUT.h"
#include "HelpScene.h"

void HelpScene::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/HelpBG.png"
		, D3DX_DEFAULT
		, D3DX_DEFAULT
		, 1
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, 0x00000001
		, 0x00000001
		, 0xff000000
		, &m_Img
		, NULL
		, &m_Tex
	);

	pSChange = new SceneChangeObject();
	pSChange->Init(pd3dDevice);
}

void HelpScene::Update()
{
	pSChange->Update();
}

void HelpScene::Render(sprite* pd3dSprite)
{
	RECT rtTemp = { 0, 0, 1600, 900 };
	vector3 vTemp = vector3(0, 0, 0);
	pd3dSprite->Draw(
		m_Tex
		, &rtTemp
		, NULL
		, &vTemp
		, D3DXCOLOR(1, 1, 1, 1)
	);

	pSChange->Render(pd3dSprite);
}

void HelpScene::Release()
{
	pSChange->Release();
	m_Tex->Release();
}
