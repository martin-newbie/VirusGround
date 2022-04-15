#pragma once
#include "stdafx.h"
class SmallEnemy
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[10];

public:
	SmallEnemy() {}
	~SmallEnemy() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(1000, 600, 0);
	vector3 m_vVelocity = vector3(10, -10, 0);
	int m_nAniState = 0;
};

