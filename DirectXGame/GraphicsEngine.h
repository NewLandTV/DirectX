#ifndef __GRAPHICS_ENGINE_H__
#define __GRAPHICS_ENGINE_H__

#include <d3d11.h>

#pragma comment(lib, "d3d11.lib")

class GraphicsEngine
{
private:
	ID3D11Device* d3dDevice;
	D3D_FEATURE_LEVEL featureLevel;
	ID3D11DeviceContext* d3dDeviceContext;

public:
	GraphicsEngine();
	~GraphicsEngine();

	// Initialize the GraphicsEngine and DirectX 11 Device
	bool Init();

	// Release all the resources loaded
	bool Release();

	static GraphicsEngine* Get();
};

#endif