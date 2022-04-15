#pragma once
#include "stdafx.h"
class HPItem
{
private:
	image m_Img;
	texture m_Tex;

public:
	HPItem() {}
	~HPItem() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(800, 800, 0);
	vector3 m_vVelocity = vector3(-5, -5, 0);

	inline void SetPos(vector3 vec) { m_vPos = vec; }
};

