#pragma once
#include "singleton.h"
class RenderManager : public singleton<RenderManager>
{
public:
	RenderManager();
	~RenderManager();
public:
	D3DXMATRIXA16 matW;
	void Render3D(Mesh * mesh, Vec3 Pos,Vec3 Rot,Vec3 Size);
	void OutLineRender(Mesh* mesh, Vec3 Pos, Vec3 Rot, Vec3 Size);
	void ToonRender(Mesh* mesh, Vec3 Pos, Vec3 Rot, Vec3 Size);
	ID3DXEffect * OutLineShader;
	LPD3DXBUFFER OutLineBuff;

	ID3DXEffect * ToonShader;
	LPD3DXBUFFER ToonBuff;
	void AddShader(const string a);
};

#define RENDER RenderManager::GetInstance()