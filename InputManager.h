#pragma once
#include "singleton.h"
class InputManager : public singleton <InputManager>
{
public:
	InputManager();
	~InputManager();
public:
	D3DVIEWPORT9 viewPort;
	POINT pt;
	Vec3 HitPos;
	Vec3 Dir;
	Vec3 RotateVec3(Vec3 _Vec, D3DXQUATERNION _Rot)
	{
		D3DXMATRIXA16 T, R;
		D3DXMatrixTranslation(&T, _Vec.x, _Vec.y, _Vec.z);
		D3DXMatrixRotationQuaternion(&R, &_Rot);
		R *= T;
		return Vec3(R._41, R._42, R._43);
	}
	Vec3 Ray;
	void Update();
	Vec3 GetRay();
	bool Raycast(Mesh * mesh,Vec3 Pos,Vec3 Size,Vec3 Rot,Vec3 * pHitPos, D3DXMATRIX matw);
};

#define INPUT InputManager::GetInstance()
