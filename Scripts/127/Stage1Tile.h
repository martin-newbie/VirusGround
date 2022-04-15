#pragma once
#include "stdafx.h"

#define H1 9
#define W1 16
class Stage1Tile
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[H1][W1];

public:
	bool m_bCell[H1][W1];

	Stage1Tile() {}
	~Stage1Tile() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

};

