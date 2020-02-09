#pragma once

#include "../valkyr/core/vcommon.h"
#include "../valkyr/core/vplatform.h"
#include "../valkyr/core/vptr.h"
#include "../valkyr/render/Renderer.h"
#include <dxgi.h>
#include <d3d11.h>
#include <d3dcompiler.h>

using namespace valkyr;

struct SimpleVertex
{
	vfloat3 Position;  
	vfloat4 Color;  
};

struct ConstantBuffer
{
	vMatrix mWorld; 
	vMatrix mView; 
	vMatrix mProjection;  
};

class D3d12Renderer:public Renderer
{
public:
	D3d12Renderer();
	virtual ~D3d12Renderer();

	virtual vint initGraphics(vptr<Config> pConfig,vhwnd hwnd) override;
	//virtual vint loadRes();
	//virtual void start();
	//virtual void stop();
	void preRender() override;
	void render() override;
	//virtual void generateRenderList();
	//virtual void drawScenePass();
	//virtual void drawLightPass();
	//virtual void drawCompositionPass();
	//virtual void drawPostFX();
	void destroy() override;
	//virtual void createWindow();

private:
	vint compileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	//void setupCamera();

	D3D_DRIVER_TYPE         m_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       m_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*           m_pd3dDevice = NULL;
	ID3D11DeviceContext*    m_pImmediateContext = NULL;
	IDXGISwapChain*         m_pSwapChain = NULL;
	ID3D11VertexShader*     m_pVertexShader = NULL;
	ID3D11PixelShader*      m_pPixelShader = NULL;
	ID3D11InputLayout*      m_pVertexLayout = NULL;
	ID3D11Buffer*           m_pVertexBuffer = NULL;
	ID3D11Buffer*           m_pIndexBuffer = NULL;
	ID3D11Buffer*           m_pConstantBuffer = NULL;
	ID3DBlob* m_pVSBlob, *m_pPSBlob;
	UINT mWidth, mHeight;

	ID3D11RenderTargetView* m_pMainRTV = NULL;

	vMatrix                m_World;
	vMatrix                m_View;
	vMatrix                m_Projection;

};

