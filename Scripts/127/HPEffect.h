#pragma once
#include "stdafx.h"

class HPEffect
{
private:
	image m_Img[12];
	texture m_Tex[12];

public:
	HPEffect() {}
	~HPEffect() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	int m_nAniState = 0;
	int m_nCurCnt = 0;

	vector3 m_vpos = vector3(0, 0, 0);
	inline void SetPos(vector3 vec3) { m_vpos = vec3; }
};

