#pragma once
#include "stdafx.h"

class EndSceneObject
{
private:
	image m_Img;
	texture m_Tex;

public:
	EndSceneObject() {}
	~EndSceneObject() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	vector3 m_vPos = vector3(1600, 0, 0);
	vector3 m_vVelocity = vector3(-100, 0, 0);
};

