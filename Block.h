#pragma once
#include "Component.h"
class Block : public Component
{
public:
	Block();
	~Block();
public:


	// Component��(��) ���� ��ӵ�
	virtual void Init() override;

	virtual void Update() override;

	virtual void Render() override;

	virtual void Release() override;

};

