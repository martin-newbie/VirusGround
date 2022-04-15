#pragma once
#include "stdafx.h"
class ShieldEffect
{
private:
	image m_Img;
	texture m_Tex;

public:
	ShieldEffect() {}
	~ShieldEffect() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3( 0, 0, 0 );
	inline void SetPos(vector3 vPos) { m_vPos = vPos; }
};

