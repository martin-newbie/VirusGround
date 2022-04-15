#pragma once
#include "stdafx.h"
class Stage2BG
{
private:
	image m_Img;
	texture m_Tex;

public:
	Stage2BG() {}
	~Stage2BG() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();
};

