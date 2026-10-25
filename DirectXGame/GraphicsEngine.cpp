// Creation Date: 2022.09.25. Sun, 09:38:35
// Modified Date: 2022.09.25. Sun, 10:17:28
#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{

}

GraphicsEngine::~GraphicsEngine()
{

}

bool GraphicsEngine::Init()
{
	D3D_DRIVER_TYPE driverTypes[3] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE
	};

	UINT driverTypesLength = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[1] =
	{
		D3D_FEATURE_LEVEL_11_0
	};

	UINT featureLevelsLength = ARRAYSIZE(featureLevels);

	HRESULT result = 0;

	for (UINT driverTypeIndex = 0; driverTypeIndex < driverTypesLength; driverTypeIndex++)
	{
		result = D3D11CreateDevice(NULL, driverTypes[driverTypeIndex], NULL, NULL, featureLevels, featureLevelsLength, D3D11_SDK_VERSION, &d3dDevice, &featureLevel, &d3dDeviceContext);

		if (SUCCEEDED(result))
		{
			break;
		}
	}

	if (FAILED(result))
	{
		return false;
	}

	return true;
}

bool GraphicsEngine::Release()
{
	d3dDeviceContext->Release();
	d3dDevice->Release();

	return true;
}

GraphicsEngine* GraphicsEngine::Get()
{
	static GraphicsEngine engine;

	return &engine;
}
