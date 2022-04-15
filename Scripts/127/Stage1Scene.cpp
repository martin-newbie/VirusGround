#include "DXUT.h"
#include "Stage1Scene.h"
#include "GameSystem.h"

extern GameSystem* pGS;
void Stage1Scene::Init(device* pd3dDevice)
{
	pBG = new Stage1BG();
	pBG->Init(pd3dDevice);

	pTile = new Stage1Tile();
	pTile->Init(pd3dDevice);

	pPlayer = new Stage1Player();
	pPlayer->Init(pd3dDevice);

	pBEnemy = new BigEnemy();
	pBEnemy->Init(pd3dDevice);
	
	pSEnemy = new SmallEnemy();
	pSEnemy->Init(pd3dDevice);
	
	pDEnemy = new DodgeEnemy();
	pDEnemy->Init(pd3dDevice);

	pBoss = new Stage1Boss();
	pBoss->Init(pd3dDevice);

	pInfected = new Stage1InfectedBG();
	pInfected->Init(pd3dDevice);

	pSChange = new SceneChangeObject();
	pSChange->Init(pd3dDevice);

	pEx = new ExplosionObj();
	pEx->Init(pd3dDevice);

	pHP = new HPItem();
	pHP->Init(pd3dDevice);

	pHPEffect = new HPEffect();
	pHPEffect->Init(pd3dDevice);

	pShield = new ShieldEffect();
	pShield->Init(pd3dDevice);
}

void Stage1Scene::Update()
{
	pBG->Update();
	pTile->Update();
	pPlayer->Update();
	pBEnemy->Update();
	pSEnemy->Update();
	pDEnemy->Update();
	pBoss->Update();
	pInfected->Update();
	pSChange->Update();
	pHP->Update();

	if (m_bProof)
	{
		vector3 vTemp = vector3(pPlayer->m_vPos.x - 60, pPlayer->m_vPos.y - 80, 0);
		pShield->SetPos(vTemp);
		pShield->Update();
	}

	int x, y;
	x = pPlayer->m_CelX;
	y = pPlayer->m_CelY;
	if (pTile->m_bCell[y][x])
	{
		mciSendString(L"play ./Wave/casing-sound-2.wav", NULL, 0, NULL);
		pTile->m_bCell[y][x] = false;
	}
	if (!(pInfected->m_bCell[y][x]))
	{
		mciSendString(L"play ./Wave/casing-sound-2.wav", NULL, 0, NULL);
		pInfected->m_bCell[y][x] = true;
	}

	int ix, iy;
	ix = pBoss->m_CelX;
	iy = pBoss->m_CelY;
	pInfected->m_bCell[iy][ix + 1] = false;
	pInfected->m_bCell[iy][ix - 1] = false;
	pInfected->m_bCell[iy + 1][ix] = false;
	pInfected->m_bCell[iy - 1][ix] = false;
	if (pInfected->m_bCell[iy][ix])
	{
		pInfected->m_bCell[iy][ix] = false;
		mciSendString(L"play ./Wave/thud.wav", NULL, 0, NULL);
	}
	

	RECT rtPlayer = { pPlayer->m_vPos.x, pPlayer->m_vPos.y, pPlayer->m_vPos.x + 128, pPlayer->m_vPos.y + 50 };
	RECT rtBEnemy = { pBEnemy->m_vPos.x, pBEnemy->m_vPos.y, pBEnemy->m_vPos.x + 128, pBEnemy->m_vPos.y + 50 };
	RECT rtSEnemy = { pSEnemy->m_vPos.x, pSEnemy->m_vPos.y, pSEnemy->m_vPos.x + 64, pSEnemy->m_vPos.y + 24 };
	RECT rtDEnemy = { pDEnemy->m_vPos.x, pDEnemy->m_vPos.y, pDEnemy->m_vPos.x + 128, pDEnemy->m_vPos.y + 50 };
	RECT rtBoss = { pBoss->m_vPos.x, pBoss->m_vPos.y, pBoss->m_vPos.x + 128, pBoss->m_vPos.y + 50 };
	RECT rtHP = { pHP->m_vPos.x, pHP->m_vPos.y, pHP->m_vPos.x + 134, pHP->m_vPos.y + 105 };
	RECT rtTemp = {};
	static int cnt2 = 0;

	if (IntersectRect(&rtTemp, &rtPlayer, &rtHP))
	{
		vector3 vTemp;
		vTemp.x = rand() % 1600 - 200;
		vTemp.y = rand() % 900 - 100;
		pHP->SetPos(vTemp);
		vector3 vTemp2 = pPlayer->m_vPos;
		pHPEffect->SetPos(vTemp2);
		m_bIsCured = true;
		m_nLife++;
		cnt2 = 0;
		mciSendString(L"play ./Wave/Cure.wav", NULL, 0, NULL);
	}

	if (m_nLife <= 0)
	{
		mciSendString(L"play ./Wave/Exploding.wav", NULL, 0, NULL);
		pGS->m_CurScene = SceneState::MENU;
		m_nLife = 5;

		for (int y = 0; y < H1; y++)
		{
			for (int x = 0; x < W1; x++)
			{
				pTile->m_bCell[y][x] = true;
				pInfected->m_bCell[y][x] = true;
			}
		}
	}
	static int cnt = 0;

	if (pPlayer->m_bProof != true)
	{
		if (IntersectRect(&rtTemp, &rtPlayer, &rtBEnemy) || IntersectRect(&rtTemp, &rtPlayer, &rtSEnemy) || IntersectRect(&rtTemp, &rtPlayer, &rtDEnemy) || IntersectRect(&rtTemp, &rtPlayer, &rtBoss))
		{
			vector3 vTemp = pPlayer->m_vPos;
			vTemp.x -= 80;
			vTemp.y -= 80;
			pEx->SetPos(vTemp);

			mciSendString(L"play ./Wave/impact.wav", NULL, 0, NULL);
			m_nLife--;
			pPlayer->m_CelX = 0;
			pPlayer->m_CelY = 0;
			pBEnemy->m_vPos = vector3(500, 600, 0);
			pSEnemy->m_vPos = vector3(1000, 600, 0);
			pDEnemy->m_vPos = vector3(1200, 800, 0);


			cnt = 0;
			pPlayer->m_bChk = true;
			pPlayer->m_bProof = true;
			m_bIsDamaged = true;
		}
	}
	
	if (++cnt > 200 && !m_bProof)
	{
		pPlayer->m_bChk = false;
		pPlayer->m_bProof = false;
	}

	if (++cnt > 144)
	{
		m_bIsDamaged = false;
	}
	else if (m_bIsDamaged)
	{
		pEx->Update();
	}

	if (++cnt2 > 20)
	{
		m_bIsCured = false;
	}
	else if (m_bIsCured)
	{
		pHPEffect->Update();
	}

	int nF = 0, nT = 0;
	for (int y = 0; y < H1; y++)
	{
		for (int x = 0; x < W1; x++)
		{
			if (pTile->m_bCell[y][x]) nT++;
			else nF++;
		}
	}

	int inF = 0, inT = 0;
	for (int y = 0; y < H1; y++)
	{
		for (int x = 0; x < W1; x++)
		{
			if (pInfected->m_bCell[y][x]) inT++;
			else inF++;
		}
	}

	m_nScore = ((float)nF / ((H1 - 1) * W1)) * 100.0f;
	m_nDisScore = ((float)inF / ((H1 - 1) * W1)) * 100.0f;

	if (m_nScore >= 80)
	{
		mciSendString(L"play ./Wave/zone_enter.wav", NULL, 0, NULL);
		for (int y = 0; y < H1; y++)
		{
			for (int x = 0; x < W1; x++)
			{
				pTile->m_bCell[y][x] = true;
				pInfected->m_bCell[y][x] = true;
			}
		}

		m_nLife = 5;
		pGS->m_CurScene = SceneState::STAGE2;
	}

	if (m_nDisScore >= 60)
	{
		m_nLife = 0;
	}
}

void Stage1Scene::Render(sprite* pd3dSprite)
{
	pBG->Render(pd3dSprite);
	pTile->Render(pd3dSprite);
	pInfected->Render(pd3dSprite);
	pPlayer->Render(pd3dSprite);
	pBEnemy->Render(pd3dSprite);
	pSEnemy->Render(pd3dSprite);
	pDEnemy->Render(pd3dSprite);
	pBoss->Render(pd3dSprite);
	if (m_bIsDamaged) pEx->Render(pd3dSprite);
	pHP->Render(pd3dSprite);
	pSChange->Render(pd3dSprite);
	if (m_bIsCured) 
		pHPEffect->Render(pd3dSprite);
	if (m_bProof)
	{
		pShield->Render(pd3dSprite);
	}
}

void Stage1Scene::Release()
{
	pHP->Release();
	pBoss->Release();
	pBG->Release();
	pTile->Release();
	pInfected->Release();
	pPlayer->Release();
	pBEnemy->Release();
	pSEnemy->Release();
	pDEnemy->Release();
	pSChange->Release();
	pEx->Release();
	pHPEffect->Release();
	pShield->Release();
}
