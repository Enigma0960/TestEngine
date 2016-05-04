#pragma once
#include <d3d11.h>
#include <d3dx10math.h>
#include <d3dx11async.h>

class Shader {
public:
	Shader(ID3D11Device* device, HWND hWnd);
	~Shader();
	void  Render(ID3D11DeviceContext* deviceContext, int indexCount);
	bool SetShaderParameters(ID3D11DeviceContext* deviceContext, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix);
private:
	struct MatrixBufferType
	{
		D3DXMATRIX world;
		D3DXMATRIX view;
		D3DXMATRIX projection;
	};

	ID3D11VertexShader* m_VertexShader;
	ID3D11PixelShader* m_PixelShader;
	ID3D11InputLayout* m_Layout;
	ID3D11Buffer* m_MatrixBuffer;
};

