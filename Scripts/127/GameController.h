#pragma once
#include "stdafx.h"
class GameController
{

public:
	GameController() {}
	~GameController() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	bool m_bBulletProof = false;
};

