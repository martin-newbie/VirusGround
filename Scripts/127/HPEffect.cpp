#include "DXUT.h"
#include "HPEffect.h"
TCHAR*	CureImage[] = {
	L"./Image/Cure/light_glow_01.png",
	L"./Image/Cure/light_glow_02.png",
	L"./Image/Cure/light_glow_03.png",
	L"./Image/Cure/light_glow_04.png",
	L"./Image/Cure/light_glow_05.png",
	L"./Image/Cure/light_glow_06.png",
	L"./Image/Cure/light_glow_07.png",
	L"./Image/Cure/light_glow_08.png",
	L"./Image/Cure/light_glow_09.png",
	L"./Image/Cure/light_glow_10.png",
};

void HPEffect::Init(device* pd3dDevice)
{
	for (int i = 0; i < 10; i++)
	{
		D3DXCreateTextureFromFileEx(
			pd3dDevice
			, CureImage[i]
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

void HPEffect::Update()
{
	static int cnt = 0;
	if (++cnt > 1)
	{
		if (m_nAniState >= 9) m_nAniState = 0;
		else m_nAniState++;

		cnt = 0;
	}
}

void HPEffect::Render(sprite* pd3dSprite)
{
	RECT rtTemp = { 0, 0, 64, 64 };
	pd3dSprite->Draw(
		m_Tex[m_nAniState]
		, &rtTemp
		, NULL
		, &m_vpos
		, D3DXCOLOR(1, 1, 1, 1)
	);
}

void HPEffect::Release()
{
	for (int i = 0; i < 10; i++) SAFE_RELEASE(m_Tex[i]);
}
