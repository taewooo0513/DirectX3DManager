#include "DXUT.h"
#include "CameraManager.h"

CameraManager::CameraManager()
{
}

CameraManager::~CameraManager()
{
}

void CameraManager::ResetCamPos()
{
	Pos = Vec3(0,0,0);
	Look = Vec3(0, 0, 0);
	At = Vec3(0, 1, 0);

}

void CameraManager::SetCamPos(Vec3 Pos, Vec3 Look, Vec3 At)
{
	this->Pos = Pos;
	this->Look = Look;
	this->At = At;
}

void CameraManager::Update()
{
	D3DXMatrixOrthoLH(&matP, WINX, WINY, 0, 100);
	D3DXMatrixPerspectiveFovLH(&matP, D3DXToRadian(60), 16.f / 9.f, 1.f, 50000.f);
	Device->SetTransform(D3DTS_PROJECTION, &matP);
	D3DXMatrixLookAtLH(&matV, &Pos, &Look, &At);
	Device->SetTransform(D3DTS_VIEW, &matV);
}
