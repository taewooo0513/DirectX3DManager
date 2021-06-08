#include "DXUT.h"
#include "InputManager.h"

InputManager::InputManager()
{
	Device->GetViewport(&viewPort);
}

InputManager::~InputManager()
{
}

void InputManager::Update()
{
	GetCursorPos(&pt);
	ScreenToClient(DXUTGetHWND(), &pt);
}

Vec3 InputManager::GetRay()
{
	
	float px = pt.x * 2.0f / viewPort.Width - 1.0f;
	float py = pt.y * -2.0f / viewPort.Height + 1.0f;
	px /= CAMERA->matP(0, 0);
	py /= CAMERA->matP(1, 1);

	Vec3 Dir;
	D3DXVec3Normalize(&Dir, &Vec3(px, py, 1));
	D3DXMATRIXA16 matI;
	D3DXMatrixInverse(&matI,0, &CAMERA->matV);
	D3DXVec3TransformNormal(&Dir, &Dir, &matI);

	return Dir;
}

bool InputManager::Raycast(Mesh* mesh, Vec3 Pos, Vec3 Size, Vec3 Rot, Vec3* pHitPos, D3DXMATRIX matw)
{
	D3DXQUATERNION InvRot;
	D3DXQUATERNION Qx, Qy, Qz,Qa;
	D3DXQuaternionRotationAxis(&Qy, &Vec3(1, 0, 0), Rot.x);
	D3DXQuaternionRotationAxis(&Qx, &Vec3(0, 1, 0), Rot.y);
	D3DXQuaternionRotationAxis(&Qz, &Vec3(0, 0, 1), Rot.z);
	Qa = Qx * Qy * Qz;
	
	D3DXQuaternionInverse(&InvRot, &Qa);
	Vec3 LocalPos = RotateVec3(CAMERA->Pos - Pos, InvRot);
	LocalPos.x /= Size.x;
	LocalPos.y /= Size.y;
	LocalPos.z /= Size.z;
	Vec3 Dir = GetRay();
	Vec3 LocalDir = RotateVec3(Dir, InvRot);
	LocalDir.x /= Size.x;
	LocalDir.y /= Size.y;
	LocalDir.z /= Size.z;
	int isHit = false;
	float Dist;
	D3DXIntersect(mesh->mesh, &LocalPos, &LocalDir, &isHit, 0, 0, 0, &Dist, 0, 0);
	*pHitPos = CAMERA->Pos + Dir * Dist;
	return isHit;
}
