#include "DXUT.h"
#include "RenderComponent.h"

RenderComponent::RenderComponent()
{
}

RenderComponent::~RenderComponent()
{
}

void RenderComponent::Init()
{
	//cout << "gdgd";

}

void RenderComponent::Update()
{
}

void RenderComponent::Render()
{
	RENDER->Render3D(mesh,obj->Pos,obj->Rot,obj->Size);
	//cout << "gd";
}

void RenderComponent::Release()
{
}
