#include "DXUT.h"
#include "SmallEnemy.h"

void SmallEnemy::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/Player.png"
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

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 2; x++)
		{
			int offset = y * 2 + x;
			m_rtCell[offset].left = m_Img.Width / 2 * (x + 0);
			m_rtCell[offset].top = m_Img.Height / 5 * (y + 0);
			m_rtCell[offset].right = m_Img.Width / 2 * (x + 1);
			m_rtCell[offset].bottom = m_Img.Height / 5 * (y + 1);
		}
	}
}

void SmallEnemy::Update()
{
	if (m_vPos.x <= 0) m_vVelocity.x *= -1;
	if (m_vPos.x >= 1600 - 64) m_vVelocity.x *= -1;
	if (m_vPos.y <= 0) m_vVelocity.y *= -1;
	if (m_vPos.y >= 900 - 25) m_vVelocity.y *= -1;

	static int cnt = 0;
	if (++cnt > 5)
	{
		if (m_nAniState >= 9) m_nAniState = 0;
		else m_nAniState++;
		cnt = 0;
	}

	m_vPos += m_vVelocity;
}

void SmallEnemy::Render(sprite* pd3dSprite)
{
	pd3dSprite->Draw(
		m_Tex
		, &m_rtCell[m_nAniState]
		, NULL
		, &m_vPos
		, D3DXCOLOR(1, 0, 0, 1)
	);
}

void SmallEnemy::Release()
{
	m_Tex->Release();
}
