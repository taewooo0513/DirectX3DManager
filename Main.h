#pragma once
class Main
{
public:
	Main();
	~Main();
public:
	void LoadResource(IDirect3DDevice9* device);
	void Init();
	void Update();
	void Render();
	void Release();
	void ResetDevice();
	void LostDevice();
};

