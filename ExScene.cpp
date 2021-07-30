#include "DXUT.h"
#include "ExScene.h"
#include "ExTower.h"
#include "Block.h"
ExScene::ExScene()
{
}

ExScene::~ExScene()
{
}

void ExScene::Init()
{
	OBJ->AddObject("Ex", Vec3(0, 0, 0), 0)->Addcomponent<ExTower>();
	OBJ->AddObject("Block", Vec3(0, 0, 0), 0)->Addcomponent<Block>();

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
