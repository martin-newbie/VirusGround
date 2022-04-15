#pragma once
#include "stdafx.h"

class Stage1Player
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[10];

public:
	Stage1Player() {}
	~Stage1Player() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(0, 0, 0);
	int m_CelX = 0, m_CelY = 0;
	int m_nAniState = 0;

	void Damaged();
	int m_nAlpha = 1;
	bool m_bChk = true;
	bool m_bProof = false;
};

