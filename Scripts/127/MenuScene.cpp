#include "DXUT.h"
#include "MenuScene.h"

TCHAR* TitleImage[] = {
	L"./Image/title0.png",
	L"./Image/title1.png",
	L"./Image/title2.png",
	L"./Image/title3.png",
};

RECT rtButtonPos[]{
	{939, 215, 1320, 268},
	{939, 382, 1320, 434},
	{939, 542, 1320, 601},
};

void MenuScene::Init(device* pd3dDevice)
{
	for (int i = 0; i < 4; i++)
	{
		D3DXCreateTextureFromFileEx(
			pd3dDevice
			, TitleImage[i]
			, D3DX_DEFAULT
			, D3DX_DEFAULT
			, 1
			, 0
			, D3DFMT_UNKNOWN
			, D3DPOOL_MANAGED
			, 0x00000001
			, 0x00000001
			, 0xff000000
			, &m_Img[i]
			, NULL
			, &m_Tex[i]
		);
	}
	pSChange = new SceneChangeObject();
	pSChange->Init(pd3dDevice);
}

void MenuScene::Update()
{
	m_nCurState = 0;
	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(&rtButtonPos[i], m_ptMousePos))
		{
			m_nCurState = i + 1;
		}
	}
	pSChange->Update();
}

void MenuScene::Render(sprite* pd3dSprite)
{
	RECT rtTemp = { 0, 0, 1600, 900 };
	vector3 vTemp = vector3(0, 0, 0);

	pd3dSprite->Draw(
		m_Tex[m_nCurState]
		, &rtTemp
		, NULL
		, &vTemp
		, D3DXCOLOR(1, 1, 1, 1)
	);

	pSChange->Render(pd3dSprite);
}

void MenuScene::Release()
{
	pSChange->Release();
	for (int i = 0; i < 4; i++) m_Tex[i]->Release();
}
