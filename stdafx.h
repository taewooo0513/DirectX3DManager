#pragma once
#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#ifndef __DEPENDENCY_HLSL__
#define __DEPENDENCY_HLSL__

float x() { return 0; }

#endif // __DEPENDENCY_HLSL__


#include <iostream>
#include <math.h>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <math.h>
#include <random>

using namespace std;

#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3
#define Device DXUTGetD3D9Device()
const int WINX = 1920;
const int WINY = 1080;



enum Tag
{
	Begin,
	End
};

#include "LoadManager.h"
#include "CameraManager.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "ObjectManager.h"