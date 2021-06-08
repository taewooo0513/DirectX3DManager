#include "DXUT.h"
#include "ExScene.h"
#include "ExTower.h"
ExScene::ExScene()
{
}

ExScene::~ExScene()
{
}

void ExScene::Init()
{
	OBJ->AddObject("Ex", Vec3(0, 0, 0), 0)->Addcomponent<ExTower>();
}

void ExScene::Update()
{
}

void ExScene::Render()
{
}

void ExScene::Release()
{
}
