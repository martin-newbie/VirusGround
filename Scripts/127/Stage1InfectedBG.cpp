#include "DXUT.h"
#include "Stage1InfectedBG.h"

void Stage1InfectedBG::Init(device* pd3dDevice)
{
	D3DXCreateTextureFromFileEx(
		pd3dDevice
		, L"./Image/Stage2Infected.png"
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

	for (int y = 0; y < H1; y++)
	{
		for (int x = 0; x < W1; x++)
		{
			m_rtCell[y][x].left = m_Img.Width / W1 * (x + 0);
			m_rtCell[y][x].top = m_Img.Height / H1 * (y + 0);
			m_rtCell[y][x].right = m_Img.Width / W1 * (x + 1);
			m_rtCell[y][x].bottom = m_Img.Height / H1 * (y + 1);
		}
	}

	for (int y = 0; y < H1; y++)
	{
		for (int x = 0; x < W1; x++)
		{
			m_bCell[y][x] = true;
		}
	}
}

void Stage1InfectedBG::Update()
{
}

void Stage1InfectedBG::Render(sprite* pd3dSprite)
{
	for (int y = 0; y < H1; y++)
	{
		for (int x = 0; x < W1; x++)
		{
			if (!m_bCell[y][x])
			{
				vector3 vTemp = vector3(m_rtCell[y][x].left, m_rtCell[y][x].top, 0);
				pd3dSprite->Draw(
					m_Tex
					, &m_rtCell[y][x]
					, NULL
					, &vTemp
					, D3DXCOLOR(1, 1, 1, 1)
				);
			}
		}
	}
}

void Stage1InfectedBG::Release()
{
	m_Tex->Release();
}
