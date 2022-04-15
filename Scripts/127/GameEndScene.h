#pragma once
#include "stdafx.h"
#include "SceneChangeObject.h"
#include "EndSceneObject.h"

class GameEndScene
{
private:
	image m_Img;
	texture m_Tex;

public:

	GameEndScene() {}
	~GameEndScene() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	SceneChangeObject* pSChange = NULL;
	EndSceneObject* pObj = NULL;
};

