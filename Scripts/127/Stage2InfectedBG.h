#pragma once
#include "stdafx.h"
#include "Stage2Tile.h"
class Stage2InfectedBG
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[H2][W2];

public:
	bool m_bCell[H2][W2];

	Stage2InfectedBG() {}
	~Stage2InfectedBG() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();
};

