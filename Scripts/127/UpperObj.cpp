#include "DXUT.h"
#include "UpperObj.h"

void UpperObj::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/Lower.png"
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

void UpperObj::Update()
{
	m_vPos += m_vVelocity;
}

void UpperObj::Render(sprite* pd3dSprite)
{
	RECT rtTemp = { 0, 0, 1600, 900 };
	pd3dSprite->Draw(
		m_Tex
		, &rtTemp
		, NULL
		, &m_vPos
		, D3DXCOLOR(1, 1, 1, 1)
	);
}

void UpperObj::Release()
{
	m_Tex->Release();
}
