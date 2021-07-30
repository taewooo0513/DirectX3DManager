#include "DXUT.h"
#include "Block.h"
#include "RenderComponent.h"
Block::Block()
{
}

Block::~Block()
{
}

void Block::Init()
{
	Addcomponent<RenderComponent>();
	Getcomponent<RenderComponent>()->mesh = LOADER->FindMesh("Block");
	
	obj->Pos = Vec3(0, -1, -10);
	obj->Size = Vec3(0.1, 0.1, 0.1);
}

void Block::Update()
{
	Vec3 H;
	D3DXMATRIXA16 mat;
	mat = Getcomponent<RenderComponent>()->GetMatW();
	if (DXUTIsKeyDown(VK_LBUTTON))
	{
	if (INPUT->Raycast(Getcomponent<RenderComponent>()->mesh, obj->Pos, obj->Size, obj->Rot, &H, mat))
	{
		cout << H.z << endl;
		RENDER->OutLineRender(Getcomponent<RenderComponent>()->mesh, obj->Pos, obj->Rot, obj->Size);
	}
	}
}

void Block::Render()
{
}

void Block::Release()
{
}
