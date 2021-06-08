#pragma once
#include "Component.h"
class Object
{
public:
	string name;
	Vec3 Pos = { 0,0,0 }, Rot = { 0,0,0 }, Size = { 1,1,1 };
	
	
	bool Destroy = false;
public:
	Object();
	~Object();
	void Init();
	void Update();
	void Render();
	void Release();
public:
	list<Component*> components;
	template<class T>
	T* Addcomponent()
	{
		T* a = new T;
		a->obj = this;
		components.push_back(a);
		a->Init();
		return a;
	}
	template<class T>
	T* Getcomponent()
	{
		for (auto& iter : components)
		{
			if (typeid(*iter) == typeid(T))
			{
				return static_cast<T*>(iter);
			}
		}
		T* cast;
		for (auto& iter : components)
		{
			cast = dynamic_cast<T*>(iter);
			if (cast != nullptr)
			{
				return cast;
			}
		}
		return nullptr;
	}
};

