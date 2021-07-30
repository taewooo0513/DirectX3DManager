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
	obj->Size = Vec3(0.1f, 0.1f, 0.1f);
	obj->Pos = Vec3(0.f, -1.f, -10);

}

void ExTower::Update()
{
}

void ExTower::Render()
{
	Vec3 H;
	D3DXMATRIXA16 mat;
	mat = Getcomponent<RenderComponent>()->GetMatW();
	Vec2 Normal = -Vec2(obj->Pos.x - INPUT->HitPos.x , obj->Pos.z - INPUT->HitPos.z);
	D3DXVec2Normalize(&Normal, &Normal);
	if (DXUTIsKeyDown(VK_LBUTTON))
	{
		v = true;
	}
	if (v == true)
	{
		if (obj->Pos != INPUT->HitPos)
		{
			cout <<
				"황진영병신"
				;
			obj->Pos.x += Normal.x*0.2;
			obj->Pos.z += Normal.y*0.2;
		}
		else
			v = false;
	}
	if (DXUTIsKeyDown(VK_LEFT))
	{
		obj->Pos.x -= 0.1;
	}
	if (DXUTIsKeyDown(VK_RIGHT))
	{
		obj->Pos.x += 0.1;
	}
	if (DXUTIsKeyDown(VK_DOWN))
	{
		obj->Pos.y -= 0.1;
	}
	if (DXUTIsKeyDown(VK_UP))
	{
		obj->Pos.y += 0.1;
	}
	if (DXUTIsKeyDown('A'))
	{
		obj->Rot.y -= 0.1;
	}
	if (DXUTIsKeyDown('D'))
	{
		obj->Rot.y += 0.1;
	}
}

void ExTower::Release()
{

}
