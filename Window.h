#pragma once
#include <Windows.h>
#include <d3d11.h>
#include "../Maths/Color.h"

class Window {
public:
	Window(HINSTANCE hInstance, LPCSTR title, int width, int heiht, bool fullScreen = false, bool vSinc = false);
	~Window();
	
	HWND GetHWND();
	HINSTANCE GetHINSTANCE();

	void BeginScene(Color4 color);
	void BeginScene(float r, float g, float b, float a);
	void BeginScene(const float color[]);
	void EndScene();

	int GetWidth();
	int GetHeight();
	
	IDXGISwapChain* GetSwapChain();
	ID3D11Device* GetDevice();
	ID3D11DeviceContext* GetDeviceContext();
private:
	bool m_FullScreen;
	bool m_vSync;

	int m_Width;
	int m_Height;
	LPCSTR m_Title;
	LPCSTR m_ClassName;

	HWND m_hWnd;
	HINSTANCE m_hInstance;	

	IDXGISwapChain* m_SwapChain;
	ID3D11Device* m_Device;
	ID3D11DeviceContext* m_DeviceContext;
	ID3D11RenderTargetView* m_RenderTargetView;
	ID3D11Texture2D* m_DepthStencilBuffer;
	ID3D11DepthStencilState* m_DepthStencilState;
	ID3D11DepthStencilState* m_DepthDisabledStencilState;
	ID3D11DepthStencilView* m_DepthStencilView;
	ID3D11RasterizerState* m_RasterizerState;
	ID3D11BlendState* m_AlphaEnableBlandingState;
	ID3D11BlendState* m_AlphaDisableBlandingState;

	bool InitWindow();
	bool InitGraphic();
};

