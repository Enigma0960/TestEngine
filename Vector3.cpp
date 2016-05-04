#include <iostream>
#include "Vector3.h"

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(float x, float y) : x(x), y(y), z(0) {}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3::Vector3(const Vector2& vector) : z(0) {
	x = vector.x;
	y = vector.y;
}

Vector3& Vector3::Add(const Vector3& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

Vector3& Vector3::Subtract(const Vector3& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

Vector3& Vector3::Multiply(const Vector3& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
}

Vector3& Vector3::Divide(const Vector3& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	return *this;
}

Vector3& Vector3::Multiply(const float& scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	return *this;
}

Vector3& Vector3::Divide(const float& scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	return *this;
}

Vector3 operator+(Vector3 left, const Vector3& right) {
	return left.Add(right);
}

Vector3 operator-(Vector3 left, const Vector3& right) {
	return left.Subtract(right);
}

Vector3 operator*(Vector3 left, const Vector3& right) {
	return left.Multiply(right);
}

Vector3 operator/(Vector3 left, const Vector3& right) {
	return left.Divide(right);
}

Vector3 operator*(Vector3 left, const float& right) {
	return left.Multiply(right);
}

Vector3 operator/(Vector3 left, const float& right) {
	return left.Divide(right);
}

Vector3& Vector3::operator+=(const Vector3& other) {
	return Add(other);
}

Vector3& Vector3::operator-=(const Vector3& other) {
	return Subtract(other);
}

Vector3& Vector3::operator*=(const Vector3& other) {
	return Multiply(other);
}

Vector3& Vector3::operator/=(const Vector3& other) {
	return Divide(other);
}

Vector3& Vector3::operator*=(const float& scalar) {
	return Multiply(scalar);
}

Vector3& Vector3::operator/=(const float& scalar) {
	return Divide(scalar);
}

bool Vector3::operator==(const Vector3& other) {
	return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3& other) {
	return !(*this == other);
}

float Vector3::Distance(const Vector3& other) const {
	float a = x - other.x;
	float b = y - other.y;
	float c = z - other.z;
	return sqrt(a * a + b * b + c * c);
}
