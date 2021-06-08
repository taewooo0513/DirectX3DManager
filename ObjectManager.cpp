#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

Object* ObjectManager::AddObject(string name, Vec3 Pos, int tag)
{
	Object* obj =new Object;
	obj->name;
	obj->Pos = Pos;
	l_Obj[tag].push_back(obj);
	return obj;
}

void ObjectManager::Update()
{
	for (int i = 0; i < End; i++)
	{
		for (auto iter = l_Obj[i].begin();iter != l_Obj[i].end();)
		{
			(*iter)->Update();
			if ((*iter)->Destroy == true)
			{
				(*iter)->Release();
				SAFE_DELETE(*iter);
				iter = l_Obj[i].erase(iter);
			}
			else
				iter++;
		}
	}
}

void ObjectManager::Render()
{
	for (int i = 0; i < End; i++)
	{
		for (auto iter : l_Obj[i])
		{
			iter->Render();
		}
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < End; i++)
	{
		for (auto iter : l_Obj[i])
		{
			iter->Release();
			SAFE_DELETE(iter);
		}
		l_Obj[i].clear();
	}
}
