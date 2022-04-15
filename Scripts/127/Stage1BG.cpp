#include "DXUT.h"
#include "Stage1BG.h"

void Stage1BG::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/Stage2BG.png"
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
}

void Stage1BG::Update()
{
}

void Stage1BG::Render(sprite* pd3dSprite)
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
}

void Stage1BG::Release()
{
	m_Tex->Release();
}
