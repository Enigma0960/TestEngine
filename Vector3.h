#pragma once
#include "Vector2.h"

struct Vector3
{
	float x, y, z;

	Vector3();
	Vector3(float x, float y);
	Vector3(float x, float y, float z);
	Vector3(const Vector2& vector);

	Vector3& Add(const Vector3& other);
	Vector3& Subtract(const Vector3& other);
	Vector3& Multiply(const Vector3& other);
	Vector3& Divide(const Vector3& other);
	Vector3& Multiply(const float& scalar);
	Vector3& Divide(const float& scalar);

	friend Vector3 operator+(Vector3 left, const Vector3& right);
	friend Vector3 operator-(Vector3 left, const Vector3& right);
	friend Vector3 operator*(Vector3 left, const Vector3& right);
	friend Vector3 operator/(Vector3 left, const Vector3& right);
	friend Vector3 operator*(Vector3 left, const float& right);
	friend Vector3 operator/(Vector3 left, const float& right);

	Vector3& operator+=(const Vector3& other);
	Vector3& operator-=(const Vector3& other);
	Vector3& operator*=(const Vector3& other);
	Vector3& operator/=(const Vector3& other);
	Vector3& operator*=(const float& scalar);
	Vector3& operator/=(const float& scalar);

	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	float Distance(const Vector3& other) const;
};

