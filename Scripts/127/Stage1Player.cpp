#include "DXUT.h"
#include "Stage1Player.h"
#include "Stage1Tile.h"

void Stage1Player::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/BigPlayer.png"
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

void Stage1Player::Update()
{
	m_vPos.x = 1600 / W1 * m_CelX;
	m_vPos.y = 900 / H1 * m_CelY;

	if (m_CelX <= 0) m_CelX = 0;
	if (m_CelX >= W1 - 1) m_CelX = W1 - 1;
	if (m_CelY <= 0) m_CelY = 0;
	if (m_CelY >= H1 - 1) m_CelY = H1 - 1;

	static int cnt = 0;
	if (++cnt > 5)
	{
		if (m_nAniState >= 9) m_nAniState = 0;
		else m_nAniState++;
		cnt = 0;
	}

	//if (m_bChk) Damaged();
	Damaged();
}

void Stage1Player::Render(sprite* pd3dSprite)
{
	pd3dSprite->Draw(
		m_Tex
		, &m_rtCell[m_nAniState]
		, NULL
		, &m_vPos
		, D3DXCOLOR(1, 1, 1, m_nAlpha)
	);
}

void Stage1Player::Release()
{
	m_Tex->Release();
}

void Stage1Player::Damaged()
{
	static int cnt = 0;
	if (++cnt > 5)
	{
		if (m_bChk) {
			m_nAlpha = 0;
			m_bChk = false;
		}
		else {
			m_nAlpha = 1;
			m_bChk = true;
		}
		cnt = 0;
	}
}
