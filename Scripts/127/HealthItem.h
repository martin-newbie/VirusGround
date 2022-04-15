#pragma once
#include "stdafx.h"
class HealthItem
{
private:
	image m_Img;
	texture m_Tex;

public:
	HealthItem() {}
	~HealthItem() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(1000, 600, 0);
	vector3 m_vVelocity = vector3(15, -15, 0);
};

