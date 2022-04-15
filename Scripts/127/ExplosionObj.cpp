#include "DXUT.h"
#include "ExplosionObj.h"

TCHAR* ExplosionImage[] = {
	L"./Image/explosion/green_explosion_00001.png",
	L"./Image/explosion/green_explosion_00002.png",
	L"./Image/explosion/green_explosion_00003.png",
	L"./Image/explosion/green_explosion_00004.png",
	L"./Image/explosion/green_explosion_00005.png",
	L"./Image/explosion/green_explosion_00006.png",
	L"./Image/explosion/green_explosion_00007.png",
	L"./Image/explosion/green_explosion_00008.png",
	L"./Image/explosion/green_explosion_00009.png",
	L"./Image/explosion/green_explosion_00010.png",
	L"./Image/explosion/green_explosion_00011.png",
	L"./Image/explosion/green_explosion_00012.png",
	L"./Image/explosion/green_explosion_00013.png",
	L"./Image/explosion/green_explosion_00014.png",
	L"./Image/explosion/green_explosion_00015.png",
	L"./Image/explosion/green_explosion_00016.png",
	L"./Image/explosion/green_explosion_00017.png",
	L"./Image/explosion/green_explosion_00018.png",
	L"./Image/explosion/green_explosion_00019.png",
	L"./Image/explosion/green_explosion_00020.png",
	L"./Image/explosion/green_explosion_00021.png",
	L"./Image/explosion/green_explosion_00022.png",
	L"./Image/explosion/green_explosion_00023.png",
	L"./Image/explosion/green_explosion_00024.png",
};

void ExplosionObj::Init(device* pd3dDevice)
{
	for (int i = 0; i < 24; i++)
	{
		D3DXCreateTextureFromFileEx(
			pd3dDevice
			, ExplosionImage[i]
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
}

void ExplosionObj::Update()
{
	static int cnt = 0;
	if (++cnt > 2)
	{
		if (m_nAniState >= 23) m_nAniState = 0;
		else m_nAniState++;
		
		cnt = 0;
	}
}

void ExplosionObj::Render(sprite* pd3dSprite)
{
	RECT rtTemp = { 0, 0, 256, 256 };
	pd3dSprite->Draw(
		m_Tex[m_nAniState]
		, &rtTemp
		, NULL
		, &m_vpos
		, D3DXCOLOR(1, 1, 1, 1)
	);
}

void ExplosionObj::Release()
{
	for (int i = 0; i < 24; i++) SAFE_RELEASE(m_Tex[i]);
}
