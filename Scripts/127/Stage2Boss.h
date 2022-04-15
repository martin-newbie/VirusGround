#pragma once
#include "stdafx.h"
class Stage2Boss
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[10];

public:
	Stage2Boss() {}
	~Stage2Boss() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(0, 0, 0);
	int m_CelX = 6, m_CelY = 6;
	int m_nAniState = 0;
	int m_nRandPos = 0;
};

