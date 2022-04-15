#pragma once
#include "stdafx.h"
#include "IntroScene.h"
#include "MenuScene.h"
#include "HelpScene.h"
#include "Stage1Scene.h"
#include "Stage2Scene.h"
#include "GameEndScene.h"

enum SceneState {
	INTRO,
	MENU,
	HELP,
	STAGE1,
	STAGE2,
	GAMEOVER,
	GAMEEND
};
class GameSystem
{
private:
	device* m_pd3dDevice;
	sprite* m_pd3dSprite;
	font* m_pd3dFont;

public:
	GameSystem() {}
	~GameSystem() {}

	void Init(device* pd3dDevice);
	void Update();
	void PreRender();
	void Render();
	void PostRender();
	void Release();

	SceneState m_CurScene = SceneState::INTRO;
	IntroScene* pIntro = NULL;
	MenuScene* pMenu = NULL;
	HelpScene* pHelp = NULL;
	Stage1Scene* pStage1 = NULL;
	Stage2Scene* pStage2 = NULL;
	GameEndScene* pEnd = NULL;
};

