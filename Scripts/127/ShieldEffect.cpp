#include "DXUT.h"
#include "ShieldEffect.h"

void ShieldEffect::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/ShieldEffect.png"
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

void ShieldEffect::Update()
{
}

void ShieldEffect::Render(sprite* pd3dSprite)
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

void ShieldEffect::Release()
{
	SAFE_RELEASE(m_Tex);
}
