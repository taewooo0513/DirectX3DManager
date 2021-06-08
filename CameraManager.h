#pragma once
#include "singleton.h"
class CameraManager : public singleton <CameraManager>
{
public:
	CameraManager();
	~CameraManager();
public:
	D3DXMATRIXA16 matV, matP;
	Vec3 Pos; Vec3 Look; Vec3 At;
	void ResetCamPos();
	void SetCamPos(Vec3 Pos, Vec3 Look, Vec3 At);
	void Update();
};

#define CAMERA CameraManager::GetInstance()
