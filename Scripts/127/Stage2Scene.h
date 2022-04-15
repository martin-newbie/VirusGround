#pragma once
#include "stdafx.h"
#include "Stage2BG.h"
#include "Stage2Boss.h"
#include "Stage2InfectedBG.h"
#include "Stage2Player.h"
#include "Stage2Tile.h"
#include "BigEnemy.h"
#include "SmallEnemy.h"
#include "DodgeEnemy.h"
#include "SceneChangeObject.h"
#include "ExplosionObj.h"
#include "HPItem.h"
#include "HPEffect.h"
#include "ShieldEffect.h"

class Stage2Scene
{
private:

public:
	Stage2Scene() {}
	~Stage2Scene() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	Stage2BG* pBG = NULL;
	Stage2Tile* pTile = NULL;
	Stage2Player* pPlayer = NULL;
	BigEnemy* pBEnemy = NULL;
	SmallEnemy* pSEnemy = NULL;
	DodgeEnemy* pDEnemy = NULL;
	Stage2Boss* pBoss = NULL;
	Stage2InfectedBG* pInfected = NULL;
	SceneChangeObject* pSChange = NULL;
	ExplosionObj* pEx = NULL;
	HPItem* pHP = NULL;
	HPEffect* pHPEffect = NULL;
	ShieldEffect* pShield = NULL;

	int m_nScore = 0;
	int m_nDisScore = 0;
	int m_nLife = 5;

	bool m_bIsDamaged = false;
	bool m_bIsCured = false;
	bool m_bProof = false;
};

