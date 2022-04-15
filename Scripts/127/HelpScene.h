#pragma once
#include "stdafx.h"
#include "SceneChangeObject.h"
class HelpScene
{
private:
	image m_Img;
	texture m_Tex;

public:
	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	SceneChangeObject* pSChange = NULL;
};

