#pragma once
#include "Scene.h"
class ExScene : public Scene
{
public:
	ExScene();
	~ExScene();
public:
	virtual void Init() override;
	virtual void Update()override;
	virtual void Render() override;
	virtual void Release() override;
};

