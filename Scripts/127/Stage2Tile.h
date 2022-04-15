#pragma once
#include "stdafx.h"

#define H2 18
#define W2 32
class Stage2Tile
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[H2][W2];

public:
	bool m_bCell[H2][W2];

	Stage2Tile() {}
	~Stage2Tile() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();
};

