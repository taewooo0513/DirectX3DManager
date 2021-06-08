#pragma once

template <class T>
class singleton
{
private:
	static T* p;
public:
	static T* GetInstance()
	{
		if (!p)
		{
			p = new T;
		}
		return p;
	}
	static void ReleaseInstance()
	{
		if (p)
			delete p;
		p = nullptr;
	}
};

template <class T>
T* singleton<T>::p = nullptr;