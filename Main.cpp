#include "DXUT.h"
#include "Main.h"
#include "ExScene.h"
Main::Main()
{
}

Main::~Main()
{
}

void Main::LoadResource(IDirect3DDevice9* device)
{
	LOADER->AddMesh(device,"Ex",L"Resource\\(0.obj");
}

void Main::Init()
{
	SCENE->AddScene("Ex", new ExScene);
	SCENE->ChangeScene("Ex");
	CAMERA->ResetCamPos();
}

void Main::Update()
{
	CAMERA->SetCamPos(Vec3(0,0,0),Vec3(0,0,-10),Vec3(0,1,0));
	SCENE->Update();
	OBJ->Update();
	INPUT->Update();
	CAMERA->Update();
}

void Main::Render()
{
	SCENE->Render();
	OBJ->Render();
}

void Main::Release()
{
	LoadManager::ReleaseInstance();
	CameraManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
	SceneManager::ReleaseInstance();
	InputManager::ReleaseInstance();
	RenderManager::ReleaseInstance();
}

void Main::ResetDevice()
{
}

void Main::LostDevice()
{


}
