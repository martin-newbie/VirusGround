#include "DXUT.h"
#include "GameSystem.h"

void GameSystem::Init(device* pd3dDevice)
{
	m_pd3dDevice = pd3dDevice;
	D3DXCreateSprite(m_pd3dDevice, &m_pd3dSprite);
	D3DXCreateFont(pd3dDevice, 72, 0, FW_BOLD, 1, FALSE, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
		L"Arial", &m_pd3dFont);

	pIntro = new IntroScene();
	pIntro->Init(pd3dDevice);

	pMenu = new MenuScene();
	pMenu->Init(pd3dDevice);

	pHelp = new HelpScene();
	pHelp->Init(pd3dDevice);

	pStage1 = new Stage1Scene();
	pStage1->Init(pd3dDevice);

	pStage2 = new Stage2Scene();
	pStage2->Init(pd3dDevice);

	pEnd = new GameEndScene();
	pEnd->Init(pd3dDevice);
}

void GameSystem::Update()
{
	switch (m_CurScene)
	{
	case INTRO:
		pIntro->Update();
		break;
	case MENU:
		pMenu->Update();
		break;
	case HELP:
		pHelp->Update();
		break;
	case STAGE1:
		pStage1->Update();
		break;
	case STAGE2:
		pStage2->Update();
		break;
	case GAMEOVER:
		break;
	case GAMEEND:
		pEnd->Update();
		break;
	}
}

void GameSystem::PreRender()
{
    m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_ARGB(0, 45, 50, 170), 1.0f, 0);
	m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);
	m_pd3dDevice->BeginScene();
}

void GameSystem::Render()
{

	TCHAR TTemp[128];
	TCHAR TScoreTemp[128];
	RECT rtTemp = { 800, 0, 500, 600 };
	RECT rt2Temp = { 800, 60, 500, 600 };

	switch (m_CurScene)
	{
	case INTRO:
		pIntro->Render(m_pd3dSprite);
		break;
	case MENU:
		pMenu->Render(m_pd3dSprite);
		break;
	case HELP:
		pHelp->Render(m_pd3dSprite);
		break;
	case STAGE1:
		pStage1->Render(m_pd3dSprite);
		wsprintf(TTemp, L"%3d%%", pStage1->m_nScore);
		wsprintf(TScoreTemp, L"Life : %d", pStage1->m_nLife - 1);
		m_pd3dFont->DrawText(m_pd3dSprite,
			TTemp, -1, &rtTemp,
			DT_NOCLIP, D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f)); 
		m_pd3dFont->DrawText(m_pd3dSprite,
			TScoreTemp, -1, &rt2Temp,
			DT_NOCLIP, D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
		break;
	case STAGE2:
		pStage2->Render(m_pd3dSprite);
		wsprintf(TTemp, L"%3d%%", pStage2->m_nScore);
		wsprintf(TScoreTemp, L"Life : %d", pStage2->m_nLife - 1);
		m_pd3dFont->DrawText(m_pd3dSprite,
			TTemp, -1, &rtTemp,
			DT_NOCLIP, D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
		m_pd3dFont->DrawText(m_pd3dSprite,
			TScoreTemp, -1, &rt2Temp,
			DT_NOCLIP, D3DXCOLOR(0.0f, 1.0f, 1.0f, 1.0f));
		break;
	case GAMEOVER:
		break;
	case GAMEEND:
		pEnd->Render(m_pd3dSprite);
		break;
	}
}

void GameSystem::PostRender()
{
	m_pd3dSprite->End();
	m_pd3dDevice->EndScene();
}

void GameSystem::Release()
{
	pEnd->Release();
	pStage2->Release();
	pStage1->Release();
	pHelp->Release();
	pMenu->Release();
	pIntro->Release();
	m_pd3dFont->Release();
	m_pd3dSprite->Release();
}
