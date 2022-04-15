#include "DXUT.h"
#include "GameMsgProc.h"
#include "GameSystem.h"

extern GameSystem* pGS;
extern RECT rtButtonPos[];
int KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	switch (wParam)
	{
	case VK_RETURN:
		mciSendString(L"play ./Wave/back.mp3", NULL, 0, NULL);
		pGS->m_CurScene = SceneState::MENU;
		return 0;
	case VK_ESCAPE:
		SendMessage(hWnd, WM_DESTROY, wParam, lParam);
		return 0;
	case VK_UP:
		mciSendString(L"play ./Wave/ck.wav", NULL, 0, NULL);
		pGS->pStage1->pPlayer->m_CelY--;
		pGS->pStage2->pPlayer->m_CelY--;
		return 0;
	case VK_DOWN:
		mciSendString(L"play ./Wave/ck.wav", NULL, 0, NULL);
		pGS->pStage1->pPlayer->m_CelY++;
		pGS->pStage2->pPlayer->m_CelY++;
		return 0;
	case VK_LEFT:
		mciSendString(L"play ./Wave/ck.wav", NULL, 0, NULL);
		pGS->pStage1->pPlayer->m_CelX--;
		pGS->pStage2->pPlayer->m_CelX--;
		return 0;
	case VK_RIGHT:
		mciSendString(L"play ./Wave/ck.wav", NULL, 0, NULL);
		pGS->pStage1->pPlayer->m_CelX++;
		pGS->pStage2->pPlayer->m_CelX++;
		return 0;
	case VK_F1:
		if (pGS->m_CurScene == SceneState::STAGE1 || pGS->m_CurScene == SceneState::STAGE2)
		{
			pGS->pStage1->pPlayer->m_bProof = true;
			pGS->pStage1->m_bProof = !(pGS->pStage1->m_bProof);
			pGS->pStage2->pPlayer->m_bProof = true;
			pGS->pStage2->m_bProof = !(pGS->pStage2->m_bProof);
			if (pGS->pStage1->m_bProof) mciSendString(L"play ./Wave/LaserFire.wav", NULL, 0, NULL);
			else mciSendString(L"play ./Wave/Destruction.wav", NULL, 0, NULL);
		}
		return 0;
	case VK_F2:
		if (pGS->m_CurScene == SceneState::STAGE1 || pGS->m_CurScene == SceneState::STAGE2)
		{
			pGS->pStage1->pHP->m_vPos.x = rand() % 1600 - 200;
			pGS->pStage2->pHP->m_vPos.x = rand() % 1600 - 200;
			pGS->pStage1->pHP->m_vPos.y = rand() % 900 - 100;
			pGS->pStage2->pHP->m_vPos.y = rand() % 900 - 100;
			mciSendString(L"play ./Wave/Warp.wav", NULL, 0, NULL);
		}
		return 0;
	case VK_F3:
		if (pGS->m_CurScene == SceneState::STAGE1 || pGS->m_CurScene == SceneState::STAGE2)
		{
			pGS->pStage1->m_nLife++;
			pGS->pStage2->m_nLife++;
		}
		return 0;
	case VK_F4:
		if (pGS->m_CurScene == SceneState::STAGE1 || pGS->m_CurScene == SceneState::STAGE2)
		{
			pGS->pStage1->m_nLife--;
			pGS->pStage2->m_nLife--;
		}
		return 0;
	case VK_F7:
		if (pGS->m_CurScene == SceneState::STAGE1)
		{
			int x, y;
			x = rand() % 16;
			y = rand() % 9;
			pGS->pStage1->pInfected->m_bCell[y][x] = false;

			while (true)
			{
				if (pGS->pStage1->pInfected->m_bCell[y][x] == false)
				{
					x = rand() % 16;
					y = rand() % 9;
				}
				else
				{
					pGS->pStage1->pInfected->m_bCell[y][x] = false;
					return 0;
				}
			}
		}
		else if (pGS->m_CurScene == SceneState::STAGE2)
		{
			int x, y;
			x = rand() % 32;
			y = rand() % 18;
			pGS->pStage2->pInfected->m_bCell[y][x] = false;

			while (true)
			{
				if (pGS->pStage2->pInfected->m_bCell[y][x] == false)
				{
					x = rand() % 32;
					y = rand() % 18;
				}
				else
				{
					pGS->pStage2->pInfected->m_bCell[y][x] = false;
					return 0;
				}
			}
		}
		return 0;
	case VK_F8:
		if (pGS->m_CurScene == SceneState::STAGE1)
		{
			int x, y;
			x = rand() % 16;
			y = rand() % 9;
			pGS->pStage1->pInfected->m_bCell[y][x] = true;

			while (true)
			{
				if (pGS->pStage1->pInfected->m_bCell[y][x] == true)
				{
					x = rand() % 16;
					y = rand() % 9;
				}
				else
				{
					pGS->pStage1->pInfected->m_bCell[y][x] = true;
					return 0;
				}
			}
		}
		else if (pGS->m_CurScene == SceneState::STAGE2)
		{
			int x, y;
			x = rand() % 32;
			y = rand() % 18;
			pGS->pStage2->pInfected->m_bCell[y][x] = true;

			while (true)
			{
				if (pGS->pStage2->pInfected->m_bCell[y][x] == true)
				{
					x = rand() % 32;
					y = rand() % 18;
				}
				else
				{
					pGS->pStage2->pInfected->m_bCell[y][x] = true;
					return 0;
				}
			}
		}
		return 0;
	case VK_F9:
		
		if (pGS->m_CurScene == SceneState::STAGE1)
		{
			pGS->pStage1->m_nScore = 80;
			pGS->m_CurScene = SceneState::STAGE2;
		}
		else if (pGS->m_CurScene == SceneState::STAGE2)
		{
			pGS->pStage2->m_nScore = 80;
			pGS->m_CurScene = SceneState::GAMEEND;
		}
		return 0;
	case VK_F10:
		pGS->m_CurScene = SceneState::MENU;
		return 0;
	case VK_NUMPAD1:
		pGS->m_CurScene = SceneState::STAGE1;
		mciSendString(L"play ./Wave/zone_enter.wav", NULL, 0, NULL);
		return 0;
	case VK_NUMPAD2:
		pGS->m_CurScene = SceneState::STAGE2;
		mciSendString(L"play ./Wave/zone_enter.wav", NULL, 0, NULL);
		return 0;
	case VK_NUMPAD3:
		pGS->m_CurScene = SceneState::GAMEEND;
		return 0;
	}
	return 0;
}

int MouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	pGS->pMenu->m_ptMousePos.x = LOWORD(lParam);
	pGS->pMenu->m_ptMousePos.y = HIWORD(lParam);

	return 0;
}

int LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	POINT ptMouse = { 0, 0 };
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(&rtButtonPos[i], ptMouse) && pGS->m_CurScene == SceneState::MENU)
		{
			if (i == 0) pGS->m_CurScene = SceneState::STAGE1;
			if (i == 1) pGS->m_CurScene = SceneState::HELP;
			if (i == 2) SendMessage(hWnd, WM_DESTROY, wParam, lParam);
			mciSendString(L"play ./Wave/forward.mp3", NULL, 0, NULL);
		}
	}

	return 0;
}

int MainProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	switch (uMsg)
	{
	case WM_KEYDOWN:
		KeyDown(hWnd, wParam, lParam);
		return 0;
	case WM_MOUSEMOVE:
		MouseMove(hWnd, wParam, lParam);
		return 0;
	case WM_LBUTTONDOWN:
		LButtonDown(hWnd, wParam, lParam);
		return 0;
	}

	return 0;
}
