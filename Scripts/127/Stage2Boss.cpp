#include "DXUT.h"
#include "Stage2Boss.h"
#include "Stage2Tile.h"
#include <stdlib.h>
#include <time.h>

void Stage2Boss::Init(device* pd3dDevice)
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

	srand(time(NULL));
}

void Stage2Boss::Update()
{
	m_vPos.x = 1600 / W2 * m_CelX;
	m_vPos.y = 900 / H2 * m_CelY;

	if (m_CelX <= 0) m_CelX = 0;
	if (m_CelX >= W2 - 1) m_CelX = W2 - 1;
	if (m_CelY <= 0) m_CelY = 0;
	if (m_CelY >= H2 - 1) m_CelY = H2 - 1;

	static int cnt = 0;
	if (++cnt > 5)
	{
		if (m_nAniState >= 9) m_nAniState = 0;
		else m_nAniState++;
		cnt = 0;
	}

	static int RandCnt = 0;
	if (++RandCnt > 10)
	{
		m_nRandPos = rand() % 4;
		switch (m_nRandPos)
		{
		case 0:
			m_CelX++;
			break;
		case 1:
			m_CelX--;
			break;
		case 2:
			m_CelY++;
			break;
		case 3:
			m_CelY--;
			break;
		}
		RandCnt = 0;
	}
}

void Stage2Boss::Render(sprite* pd3dSprite)
{
	pd3dSprite->Draw(
		m_Tex
		, &m_rtCell[m_nAniState]
		, NULL
		, &m_vPos
		, D3DXCOLOR(1, 0, 1, 1)
	);
}

void Stage2Boss::Release()
{
	SAFE_RELEASE(m_Tex);
}