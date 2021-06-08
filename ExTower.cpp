#include "DXUT.h"
#include "ExTower.h"
#include "RenderComponent.h"
ExTower::ExTower()
{
}

ExTower::~ExTower()
{
}

void ExTower::Init()
{
	Addcomponent<RenderComponent>();
	Getcomponent<RenderComponent>()->mesh = LOADER->FindMesh("Ex");
	obj->Size = Vec3(0.2f,0.2f,0.2f);
	obj->Pos = Vec3(0.f, 0.2f, -10.f);

}

void ExTower::Update()
{
}

void ExTower::Render()
{
	cout << "gd";
	Vec3 H;
	D3DXMATRIXA16 mat;
	mat = Getcomponent<RenderComponent>()->GetMatW();
	if (INPUT->Raycast(Getcomponent<RenderComponent>()->mesh, obj->Pos, obj->Size, obj->Rot, &H,mat))
	{
		cout << H.z<<endl;
	RENDER->OutLineRender(Getcomponent<RenderComponent>()->mesh,obj->Pos,obj->Rot,obj->Size);
	}
	RENDER->ToonRender(Getcomponent<RenderComponent>()->mesh, obj->Pos, obj->Rot, obj->Size);

	if (DXUTIsKeyDown(VK_LEFT))
	{
	obj->Pos.x -= 0.1;
	}
	if (DXUTIsKeyDown(VK_RIGHT))
	{
		obj->Pos.x += 0.1;
	}

}

void ExTower::Release()
{

}
