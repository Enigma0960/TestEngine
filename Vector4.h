#pragma once
#include "Vector3.h"

struct Vector4
{
	float x, y, z, w;

	Vector4();
	Vector4(float x, float y, float z);
	Vector4(float x, float y, float z, float w);
	Vector4(const Vector3& vector);

	Vector4& Add(const Vector4& other);
	Vector4& Subtract(const Vector4& other);
	Vector4& Multiply(const Vector4& other);
	Vector4& Divide(const Vector4& other);
	Vector4& Multiply(const float& scalar);
	Vector4& Divide(const float& scalar);

	friend Vector4 operator+(Vector4 left, const Vector4& right);
	friend Vector4 operator-(Vector4 left, const Vector4& right);
	friend Vector4 operator*(Vector4 left, const Vector4& right);
	friend Vector4 operator/(Vector4 left, const Vector4& right);
	friend Vector4 operator*(Vector4 left, const float& right);
	friend Vector4 operator/(Vector4 left, const float& right);

	Vector4& operator+=(const Vector4& other);
	Vector4& operator-=(const Vector4& other);
	Vector4& operator*=(const Vector4& other);
	Vector4& operator/=(const Vector4& other);
	Vector4& operator*=(const float& scalar);
	Vector4& operator/=(const float& scalar);

	bool operator==(const Vector4& other);
	bool operator!=(const Vector4& other);
};

