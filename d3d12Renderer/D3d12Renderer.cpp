//#include "stdafx.h"
#include "D3d12Renderer.h"


D3d12Renderer::D3d12Renderer()
{

}


D3d12Renderer::~D3d12Renderer()
{
}


vint D3d12Renderer::initGraphics(vptr<Bundle> config,vhwnd hwnd)
{
	HRESULT hr = S_OK;
	UINT createDeviceFlags = 0;
#ifdef _DEBUG  
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif 
	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE(driverTypes);
	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = config->getInt(CONFIG_WIDTH);
	sd.BufferDesc.Height = config->getInt(CONFIG_HEIGHT);
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = config->getInt(CONFIG_REFRESH_RATE);
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hwnd;
	sd.Windowed = config->getInt(CONFIG_WINDOWED);
	sd.SampleDesc.Count = config->getInt(CONFIG_MSAACOUNT);
	UINT qualityLevel;
	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		m_driverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDevice(NULL, m_driverType,NULL,createDeviceFlags,featureLevels, numFeatureLevels, D3D11_SDK_VERSION, &m_pd3dDevice, &m_featureLevel, &m_pImmediateContext);
		if (SUCCEEDED(hr))
			break;
	}
	if (FAILED(hr))
		return VERR; 
	m_pd3dDevice->CheckMultisampleQualityLevels(sd.BufferDesc.Format, sd.SampleDesc.Count, &qualityLevel);
	if (sd.SampleDesc.Count == 1)
		sd.SampleDesc.Quality = 0;
	else
		sd.SampleDesc.Quality = qualityLevel-1;
	IDXGIDevice* pDxgiDevice = NULL;
	IDXGIAdapter* pDxgiAdapter = NULL;
	IDXGIFactory* pDxgiFactory = NULL;
	m_pd3dDevice->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&pDxgiDevice));
	pDxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&pDxgiAdapter));
	pDxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&pDxgiFactory));
	hr = pDxgiFactory->CreateSwapChain(m_pd3dDevice, &sd, &m_pSwapChain);
	pDxgiFactory->Release();
	pDxgiAdapter->Release();
	pDxgiDevice->Release();
	
	if (FAILED(hr))
		return VERR;
	ID3D11Texture2D* pBackBuffer = NULL;
	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	if (FAILED(hr))
		return VERR;
	hr = m_pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pMainRTV);
	pBackBuffer->Release();
	if (FAILED(hr))
		return VERR;
	m_pImmediateContext->OMSetRenderTargets(1, &m_pMainRTV, NULL);
	D3D11_VIEWPORT vp;
	/*
	vp.Width = (FLOAT)config.width;
	vp.Height = (FLOAT)config.height;
	*/
	vp.Width = config->getDouble(CONFIG_WIDTH);
	vp.Height = config->getDouble(CONFIG_HEIGHT);
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	m_pImmediateContext->RSSetViewports(1, &vp);
	/* on stack, do not need delete, otherwise it's created by new, on heap
	delete pDev;
	delete pSwapChain;
	delete pCtx;
	delete pRT;
	*/
	return VOK;
}

/*
void D3d12Renderer::generateRenderList()
{
	
	HRESULT hr = S_OK;
	hr = compileShaderFromFile(L"Tutorial.fx", "VS", "vs_4_0", &m_pVSBlob);
	if (FAILED(hr))
	{
		MessageBox(NULL,
			L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
		//return VERR;
	}
	hr = m_pd3dDevice->CreateVertexShader(m_pVSBlob->GetBufferPointer(), m_pVSBlob->GetBufferSize(), NULL, &m_pVertexShader);
	if (FAILED(hr))
	{
		m_pVSBlob->Release();
		//return VERR;
	}
	
	D3D11_INPUT_ELEMENT_DESC layout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	UINT numElements = ARRAYSIZE(layout);
	hr = m_pd3dDevice->CreateInputLayout(layout, numElements, m_pVSBlob->GetBufferPointer(),
		m_pVSBlob->GetBufferSize(), &m_pVertexLayout);
	m_pVSBlob->Release();
	if (FAILED(hr))
		//return VERR;
	m_pImmediateContext->IASetInputLayout(m_pVertexLayout);
	

}
*/

void D3d12Renderer::preRender()
{

}

void D3d12Renderer::render()
{
	float clearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };
	m_pImmediateContext->ClearRenderTargetView(m_pMainRTV, clearColor);
	m_pSwapChain->Present(0, 0);
}

/*
void D3d12Renderer::drawScenePass()
{

}

void D3d12Renderer::drawLightPass()
{

}

void D3d12Renderer::drawCompositionPass()
{

}

void D3d12Renderer::drawPostFX()
{

}
*/

vint D3d12Renderer::compileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
	HRESULT hr = S_OK;

	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )  
	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.  
	// Setting this flag improves the shader debugging experience, but still allows   
	// the shaders to be optimized and to run exactly the way they will run in   
	// the release configuration of this program.  
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif  

	ID3DBlob* pErrorBlob;
	
	//hr = D3DCompileFromFile(szFileName, NULL, NULL, szEntryPoint, szShaderModel,dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob);
	
	hr = D3DCompileFromFile(szFileName, NULL, NULL, szEntryPoint, szShaderModel,dwShaderFlags, 0, ppBlobOut,&pErrorBlob);

	if (FAILED(hr))
	{
		if (pErrorBlob != NULL)
			OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
		if (pErrorBlob) pErrorBlob->Release();
		return VERR;
	}
	if (pErrorBlob) pErrorBlob->Release();

	return VOK;
}


void D3d12Renderer::destroy()
{
	if (m_pImmediateContext) m_pImmediateContext->ClearState();

	if (m_pVertexBuffer) m_pVertexBuffer->Release();
	if (m_pVertexLayout) m_pVertexLayout->Release();
	if (m_pVertexShader) m_pVertexShader->Release();
	if (m_pPixelShader) m_pPixelShader->Release();
	if (m_pMainRTV) m_pMainRTV->Release();
	if (m_pSwapChain) m_pSwapChain->Release();
	if (m_pImmediateContext) m_pImmediateContext->Release();
	if (m_pd3dDevice) m_pd3dDevice->Release();
	if (m_pIndexBuffer) m_pIndexBuffer->Release();
	if (m_pConstantBuffer) m_pConstantBuffer->Release();
}