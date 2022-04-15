#pragma once
#include "stdafx.h"
class DodgeEnemy
{
private:
	image m_Img;
	texture m_Tex;
	RECT m_rtCell[10];

public:
	DodgeEnemy() {}
	~DodgeEnemy() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(1200, 800, 0);
	vector3 m_vVelocity = vector3(-5, 5, 0);
	int m_nAniState = 0;
};

