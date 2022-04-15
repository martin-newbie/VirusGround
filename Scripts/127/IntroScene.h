#pragma once
#include "stdafx.h"
#include "IntroBG.h"
#include "IntroObj.h"
#include "SceneChangeObject.h"


class IntroScene
{
public:
	IntroScene() {}
	~IntroScene() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	IntroBG* pBG = NULL;
	IntroObj* pObj = NULL;

	SceneChangeObject* pSChange = NULL;
};

