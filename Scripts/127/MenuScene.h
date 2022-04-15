#pragma once
#include "stdafx.h"
#include "SceneChangeObject.h"

class MenuScene
{
private:
	image m_Img[4];
	texture m_Tex[4];

public:
	int m_nCurState = 0;
	POINT m_ptMousePos = { 0, 0 };

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	SceneChangeObject* pSChange = NULL;
};

