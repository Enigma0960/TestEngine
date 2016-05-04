#pragma once
#include "../Vector.h"
#include <DirectXMath.h>

struct test : public DirectX::XMFLOAT3
{

};

struct Matrix4x4 {
	float elements[16];
	const static Matrix4x4 Identity;
	const static Matrix4x4 Zero;

	Matrix4x4();
	Matrix4x4(float num);
	Matrix4x4(const float nums[4 * 4]);
	Matrix4x4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);
	Matrix4x4(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4);
	Matrix4x4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4);
	~Matrix4x4();

	Matrix4x4& Add(const Matrix4x4& other);
	Matrix4x4& Subtract(const Matrix4x4& other);
	Matrix4x4& Multiply(const Matrix4x4& other);
	Vector4 Multiply(const Vector4& other);
	Matrix4x4& Multiply(const float& num);

	Matrix4x4 Transpose();//XMMatrixTranspose
	Matrix4x4 Inverse();//XMMatrixInverse
	float Determinant();//XMMatrixDeterminant

	friend Matrix4x4 operator+(Matrix4x4 left, const Matrix4x4& right);
	friend Matrix4x4 operator-(Matrix4x4 left, const Matrix4x4& right);

	friend Matrix4x4 operator*(Matrix4x4 left, const Matrix4x4& right);
	friend Vector4 operator*(Matrix4x4 left, const Vector4& right);
	friend Matrix4x4 operator*(Matrix4x4 left, const float& right);

	bool operator==(const Matrix4x4& other);
	bool operator!=(const Matrix4x4& other);
};

// Original matrix:
//
//     m00m01m02m03
//     m10m11m12m13
//     m20m21m22m23
//     m30m31m32m33

/*
XMMATRIX P;
P.r[0] = XMVectorMergeXY(M.r[0], M.r[2]); // m00m20m01m21
P.r[1] = XMVectorMergeXY(M.r[1], M.r[3]); // m10m30m11m31
P.r[2] = XMVectorMergeZW(M.r[0], M.r[2]); // m02m22m03m23
P.r[3] = XMVectorMergeZW(M.r[1], M.r[3]); // m12m32m13m33

XMMATRIX MT;
MT.r[0] = XMVectorMergeXY(P.r[0], P.r[1]); // m00m10m20m30
MT.r[1] = XMVectorMergeZW(P.r[0], P.r[1]); // m01m11m21m31
MT.r[2] = XMVectorMergeXY(P.r[2], P.r[3]); // m02m12m22m32
MT.r[3] = XMVectorMergeZW(P.r[2], P.r[3]); // m03m13m23m33
return MT;
*/