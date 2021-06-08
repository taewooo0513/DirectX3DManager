#include "DXUT.h"
#include "RenderManager.h"

RenderManager::RenderManager()
{
	Device->SetRenderState(D3DRS_LIGHTING, FALSE);
	Device->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
	Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	AddShader("./OutLineShader.fx");
	AddShader("./ToonShader.fx");

}

RenderManager::~RenderManager()
{
	OutLineShader->Release();
	SAFE_RELEASE(OutLineBuff);
	ToonShader->Release();
	SAFE_RELEASE(ToonBuff);
	//SAFE_DELETE();
}

void RenderManager::Render3D(Mesh* mesh, Vec3 Pos, Vec3 Rot, Vec3 Size)
{
	Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	D3DXQUATERNION Qx, Qy, Qz;
	D3DXQuaternionRotationAxis(&Qy, &Vec3(1, 0, 0), Rot.x);
	D3DXQuaternionRotationAxis(&Qx, &Vec3(0, 1, 0), Rot.y);
	D3DXQuaternionRotationAxis(&Qz, &Vec3(0, 0, 1), Rot.z);

	D3DXMatrixTransformation(&matW, nullptr, 0, &Size, nullptr, &(Qx * Qy * Qz), &Pos);
	Device->SetTransform(D3DTS_WORLD, &matW);
	for (int i = 0; i < mesh->v_material.size(); i++)
	{
		Device->SetTexture(0, mesh->v_material[i]->pTexture);
		mesh->mesh->DrawSubset(i);
	}
}

void RenderManager::OutLineRender(Mesh* mesh, Vec3 Pos, Vec3 Rot, Vec3 Size)
{
	Device->SetRenderState(D3DRS_CULLMODE,D3DCULL_CW);
	D3DXQUATERNION Qx, Qy, Qz;
	D3DXQuaternionRotationAxis(&Qy, &Vec3(1, 0, 0), Rot.x);
	D3DXQuaternionRotationAxis(&Qx, &Vec3(0, 1, 0), Rot.y);
	D3DXQuaternionRotationAxis(&Qz, &Vec3(0, 0, 1), Rot.z);

	D3DXMatrixTransformation(&matW, nullptr, 0, &Size, nullptr, &(Qx * Qy * Qz), &Pos);
	Device->SetTransform(D3DTS_WORLD, &matW);
	OutLineShader->SetFloat((D3DXHANDLE)"Size",1.5);
	OutLineShader->SetMatrix((D3DXHANDLE)"matW", &matW);
	OutLineShader->SetMatrix((D3DXHANDLE)"matPV", &(CAMERA->matV * CAMERA->matP));

	OutLineShader->Begin(0, 0);
	for (int i = 0; i < mesh->v_material.size(); i++)
	{
		OutLineShader->BeginPass(i);
		Device->SetTexture(0, mesh->v_material[i]->pTexture);
		mesh->mesh->DrawSubset(i);
		OutLineShader->CommitChanges();
		OutLineShader->EndPass();
	}
	OutLineShader->End();
}

void RenderManager::ToonRender(Mesh * mesh, Vec3 Pos, Vec3 Rot, Vec3 Size)
{
	Vec3 WorldLightNormal,WorldLightPos = Vec3(0,100,2);
	D3DXVec3Normalize(&WorldLightNormal, &(WorldLightPos - Pos));
	Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	D3DXQUATERNION Qx, Qy, Qz;
	D3DXMATRIXA16 InvW;
	D3DXQuaternionRotationAxis(&Qy, &Vec3(1, 0, 0), Rot.x);
	D3DXQuaternionRotationAxis(&Qx, &Vec3(0, 1, 0), Rot.y);
	D3DXQuaternionRotationAxis(&Qz, &Vec3(0, 0, 1), Rot.z);

	D3DXMatrixTransformation(&matW, nullptr, 0, &Size, nullptr, &(Qx * Qy * Qz), &Pos);
	Device->SetTransform(D3DTS_WORLD, &matW);
	D3DXMatrixInverse(&InvW,0,&matW);
	ToonShader->SetMatrix((D3DXHANDLE)"matW", &matW);
	ToonShader->SetMatrix((D3DXHANDLE)"ViewProjMatrix", &(CAMERA->matV*CAMERA->matP));
	ToonShader->SetValue((D3DXHANDLE)"LightDir", &WorldLightNormal,sizeof(Vec3));
	ToonShader->SetValue((D3DXHANDLE)"LightColor", &D3DXVECTOR4(1,1 ,1, 1), sizeof(D3DXVECTOR4));

	ToonShader->Begin(0, 0);
	for (int i = 0; i < mesh->v_material.size(); i++)
	{
		ToonShader->BeginPass(i);
		Device->SetTexture(0, mesh->v_material[i]->pTexture);
		mesh->mesh->DrawSubset(i);
		ToonShader->SetTexture((D3DXHANDLE)"MeshText",mesh->v_material[i]->pTexture);
		ToonShader->CommitChanges();
		ToonShader->EndPass();
	}
	ToonShader->End();
}

void RenderManager::AddShader(const string a)
{
	
	if (D3DXCreateEffectFromFileExA(Device, "./OutLineShader.fx", 0, 0, 0, D3DXFX_NOT_CLONEABLE, NULL, &OutLineShader, &OutLineBuff) == S_OK)
	{
	}
	else
	{
		MessageBoxA(DXUTGetHWND(), (LPSTR)OutLineBuff->GetBufferPointer(), NULL, NULL);
	}
	if (D3DXCreateEffectFromFileExA(Device, "./ToonShader.fx", 0, 0, 0, D3DXFX_NOT_CLONEABLE, NULL, &ToonShader, &ToonBuff) == S_OK)
	{
	}
	else
	{
		MessageBoxA(DXUTGetHWND(), (LPSTR)ToonBuff->GetBufferPointer(), NULL, NULL);
	}


}
