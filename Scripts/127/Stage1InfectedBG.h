#pragma once
#include "stdafx.h"
#include "Stage1Tile.h"
class Stage1InfectedBG
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[H1][W1];

public:
	bool m_bCell[H1][W1];

	Stage1InfectedBG() {}
	~Stage1InfectedBG() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

};

