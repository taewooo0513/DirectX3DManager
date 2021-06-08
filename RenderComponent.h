#pragma once
#include "Component.h"
class RenderComponent : public Component
{
public:
	Mesh* mesh;
	D3DXMATRIXA16 matW;
	D3DXMATRIXA16 GetMatW()
	{
		D3DXQUATERNION Qx, Qy, Qz;
		D3DXQuaternionRotationAxis(&Qy, &Vec3(1, 0, 0), obj->Rot.x);
		D3DXQuaternionRotationAxis(&Qx, &Vec3(0, 1, 0), obj->Rot.y);
		D3DXQuaternionRotationAxis(&Qz, &Vec3(0, 0, 1), obj->Rot.z);

		D3DXMatrixTransformation(&matW, nullptr, 0, &obj->Size, nullptr, &(Qx * Qy * Qz), &obj->Pos);
		return matW;
	}
	RenderComponent();
	~RenderComponent();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

