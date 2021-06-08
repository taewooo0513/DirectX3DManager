#pragma once
#include "MeshLoader.h"
class Mesh
{
public:
	Mesh() {}
	~Mesh() {}
public:
	ID3DXMesh* mesh;
	vector<Material*> v_material;
};
#include "singleton.h"
class LoadManager : public singleton<LoadManager>
{
private:
	CMeshLoader* meshloader;
public:
	LoadManager();
	~LoadManager();
public:
	LPD3D10EFFECT shader;
	map<string, Mesh*> m_mesh;
	void AddMesh(IDirect3DDevice9* device, string key, const WCHAR* path);
	Mesh* FindMesh(string key);
};

#define LOADER LoadManager::GetInstance()
