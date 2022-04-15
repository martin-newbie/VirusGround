#pragma once
#include "LowerObj.h"
#include "UpperObj.h"
#include "stdafx.h"
class SceneChangeObject
{

public:
	SceneChangeObject() {}
	~SceneChangeObject() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	LowerObj* pLower = NULL;
	UpperObj* pUpper = NULL;
};

