#pragma once
#include "stdafx.h"
class BigEnemy
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[10];

public:
	BigEnemy() {}
	~BigEnemy() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(500, 600, 0);
	vector3 m_vVelocity = vector3(-2, -2, 0);
	int m_nAniState = 0;

};

