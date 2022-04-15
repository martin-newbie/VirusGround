#include "DXUT.h"
#include "IntroScene.h"

void IntroScene::Init(device* pd3dDevice)
{
	mciSendString(L"play ./Wave/IntroBG.mp3 repeat", NULL, 0, NULL);
	pBG = new IntroBG();
	pBG->Init(pd3dDevice);

	pObj = new IntroObj();
	pObj->Init(pd3dDevice);

	pSChange = new SceneChangeObject();
	pSChange->Init(pd3dDevice);
}

void IntroScene::Update()
{
	pBG->Update();
	pObj->Update();
	pSChange->Update();
}

void IntroScene::Render(sprite* pd3dSprite)
{
	pBG->Render(pd3dSprite);
	pObj->Render(pd3dSprite);
	pSChange->Render(pd3dSprite);
}

void IntroScene::Release()
{
	pBG->Release();
	pObj->Release();
	pSChange->Release();
}
