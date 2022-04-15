#include "DXUT.h"
#include "HPItem.h"

void HPItem::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/HPItem.png"
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

void HPItem::Update()
{
	if (m_vPos.x <= 0) m_vVelocity.x *= -1;
	if (m_vPos.x >= 1600 - 64) m_vVelocity.x *= -1;
	if (m_vPos.y <= 0) m_vVelocity.y *= -1;
	if (m_vPos.y >= 900 - 25) m_vVelocity.y *= -1;

	m_vPos += m_vVelocity;
}

void HPItem::Render(sprite* pd3dSprite)
{
	RECT rtTemp = { 0, 0, 134, 105 };
	pd3dSprite->Draw(
		m_Tex
		, &rtTemp
		, NULL
		, &m_vPos
		, D3DXCOLOR(1, 1, 1, 1)
	);
}

void HPItem::Release()
{
	m_Tex->Release();
}
