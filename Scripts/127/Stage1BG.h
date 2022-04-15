#pragma once
#include "stdafx.h"

class Stage1BG
{
private:
	image m_Img;
	texture m_Tex;

public:
	Stage1BG() {}
	~Stage1BG() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();
};

