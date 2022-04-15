#pragma once
#include "stdafx.h"
class IntroObj
{
private:
	image m_Img;
	texture m_Tex;

public:
	IntroObj() {}
	~IntroObj() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(0, 900, 0);
	vector3 m_vVelocity = vector3(0, -1, 0);
};

