#pragma once
#include "stdafx.h"
#include "Stage1BG.h"
#include "Stage1Player.h"
#include "Stage1Tile.h"
#include "BigEnemy.h"
#include "SmallEnemy.h"
#include "DodgeEnemy.h"
#include "Stage1Boss.h"
#include "Stage1InfectedBG.h"
#include "SceneChangeObject.h"
#include "ExplosionObj.h"
#include "HPItem.h"
#include "HPEffect.h"
#include "ShieldEffect.h"

class Stage1Scene
{
private:

public:
	Stage1Scene() {}
	~Stage1Scene() {}

	void Init(device* pd3dDevice);
	void Update();
	void Render(sprite* pd3dSprite);
	void Release();

	Stage1BG* pBG = NULL;
	Stage1Tile* pTile = NULL;
	Stage1Player* pPlayer = NULL;
	BigEnemy* pBEnemy = NULL;
	SmallEnemy* pSEnemy = NULL;
	DodgeEnemy* pDEnemy = NULL;
	Stage1Boss* pBoss = NULL;
	Stage1InfectedBG* pInfected = NULL;
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

