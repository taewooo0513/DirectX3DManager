#include "DXUT.h"
#include "LoadManager.h"

LoadManager::LoadManager()
{
	meshloader = new CMeshLoader;

}

LoadManager::~LoadManager()
{
	for (auto iter : m_mesh)
	{
		for (auto iter_ : iter.second->v_material)
		{
			SAFE_RELEASE(iter_->pTexture);
			SAFE_DELETE(iter_)
		}
		iter.second->mesh->Release();
		iter.second->v_material.clear();
		SAFE_DELETE(iter.second);
	}
	m_mesh.clear();
	SAFE_DELETE(meshloader);
}

void LoadManager::AddMesh(IDirect3DDevice9* device, string key, const WCHAR* path)
{

	auto find = m_mesh.find(key);
	if (find == m_mesh.end())
	{
		if (meshloader->Create(Device, path) == S_OK)
		{
			Mesh* mesh = new Mesh;
			mesh->mesh = meshloader->GetMesh();
			for (int i = 0; i < meshloader->GetNumMaterials(); i++)
			{
				mesh->v_material.push_back(meshloader->GetMaterial(i));
			}
			m_mesh[key] = mesh;
			meshloader->Destroy();
		}
	}
}

Mesh* LoadManager::FindMesh(string key)
{
	return m_mesh[key];
}