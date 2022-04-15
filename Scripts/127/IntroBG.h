#pragma once
#include "stdafx.h"
class IntroBG
{
private:
	image m_Img;
	texture m_Tex;

public:
	IntroBG() {}
	~IntroBG() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();
};

