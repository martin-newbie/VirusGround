#pragma once
#include "stdafx.h"
class UpperObj
{
private:
	image m_Img;
	texture m_Tex;

	vector3 m_vPos = vector3(0, -450, 0);
	vector3 m_vVelocity = vector3(0, -10, 0);

	bool m_isStart = false;

public:
	UpperObj() {}
	~UpperObj() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();
};

