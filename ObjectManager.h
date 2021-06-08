#pragma once
#include "singleton.h"
#include "Object.h"
class ObjectManager :public singleton<ObjectManager>
{
public:
	list<Object*> l_Obj[End];
	ObjectManager();
	~ObjectManager();
public:
	Object* AddObject(string name ,Vec3 Pos,int tag );
	void Update();
	void Render();
	void Release();
};

#define OBJ ObjectManager::GetInstance()
