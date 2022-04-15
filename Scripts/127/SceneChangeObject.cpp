#include "DXUT.h"
#include "SceneChangeObject.h"

void SceneChangeObject::Init(device* pd3dDevice)
{
	mciSendString(L"play ./Wave/Horn.mp3", NULL, 0, NULL);
	pLower = new LowerObj();
	pLower->Init(pd3dDevice);

	pUpper = new UpperObj();
	pUpper->Init(pd3dDevice);
}

void SceneChangeObject::Update()
{
	pLower->Update();
	pUpper->Update();
}

void SceneChangeObject::Render(sprite* pd3dSprite)
{
	pLower->Render(pd3dSprite);
	pUpper->Render(pd3dSprite);
}

void SceneChangeObject::Release()
{
	pLower->Release();
	pUpper->Release();
}
