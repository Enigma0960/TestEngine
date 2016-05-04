#include <Windows.h>
#include <Engine\Window\Window.h>

#include "Engine\test\Model.h"
#include "Engine\test\Shader.h"

/*HRESULT CompileShaderFromFile() {
	HRESULT result = S_OK;
	
	ID3DBlob* VS = NULL;
	ID3DBlob* PS = NULL;

	ID3D10Blob* errorMessage = NULL;
	result = D3DX11CompileFromFile("color.vs", NULL, NULL, "ColorVertexShader", "vs_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL, &VS, &errorMessage, NULL);

	if (FAILED(result))
	{
		if (errorMessage) OutputDebugString((char*)errorMessage);
		return false;
	}

	result = D3DX11CompileFromFile("color.ps", NULL, NULL, "ColorPixelShader", "ps_5_0", D3D10_SHADER_ENABLE_STRICTNESS, 0, NULL, &PS, &errorMessage, NULL);

	if (FAILED(result))
	{
		if (errorMessage) OutputDebugString((char*)errorMessage);
		return false;
	}

	return result;
}*/

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(cmdLine);

	Window wnd(hInstance, "test", 800, 600);
	Model model(wnd.GetDevice());
	Shader shader(wnd.GetDevice(), wnd.GetHWND());

	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		wnd.BeginScene(0.0f, 0.0f, 0.0f, 1.0f);

		shader.Render(wnd.GetDeviceContext(), model.GetIndexCount());
		model.Render(wnd.GetDeviceContext());

		wnd.EndScene();
	}

	return static_cast<int>(msg.wParam);
}