#pragma once
class Object;
class Component
{
public:
	Component();
	virtual ~Component();
public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	virtual void OnCollision(Object * _obj,float dis);

	Object* obj;

	template<typename T>
	T* Addcomponent()
	{
		return obj->Addcomponent<T>();
	}

	template<typename T>
	T* Getcomponent()
	{
		return obj->Getcomponent<T>();
	}
};

