#pragma once
#include "Component.h"
class Tower : public Component
{
public:
	Tower();
	~Tower();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

