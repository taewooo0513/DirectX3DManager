#pragma once
#include "Tower.h"
class ExTower : public Tower
{
public:
	ExTower();
	~ExTower();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

