#include "Vector4.h"

Vector4::Vector4() : x(0), y(0), z(0), w(0) {}

Vector4::Vector4(float x, float y, float z) : x(x), y(y), z(z), w(0) {}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector3& vector) : w(w) {
	x = vector.x;
	y = vector.y;
	z = vector.z;
}

Vector4& Vector4::Add(const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4& Vector4::Subtract(const Vector4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4& Vector4::Multiply(const Vector4& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	w *= other.w;
	return *this;
}

Vector4& Vector4::Divide(const Vector4& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	w /= other.w;
	return *this;
}

Vector4& Vector4::Multiply(const float& scalar) {
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
	return *this;
}

Vector4& Vector4::Divide(const float& scalar) {
	x /= scalar;
	y /= scalar;
	z /= scalar;
	w /= scalar;
	return *this;
}

Vector4 operator+(Vector4 left, const Vector4& right) {
	return left.Add(right);
}

Vector4 operator-(Vector4 left, const Vector4& right) {
	return left.Subtract(right);
}

Vector4 operator*(Vector4 left, const Vector4& right) {
	return left.Multiply(right);
}

Vector4 operator/(Vector4 left, const Vector4& right) {
	return left.Divide(right);
}

Vector4 operator*(Vector4 left, const float& right) {
	return left.Multiply(right);
}

Vector4 operator/(Vector4 left, const float& right) {
	return left.Divide(right);
}

Vector4& Vector4::operator+=(const Vector4& other) {
	return Add(other);
}

Vector4& Vector4::operator-=(const Vector4& other) {
	return Subtract(other);
}

Vector4& Vector4::operator*=(const Vector4& other) {
	return Multiply(other);
}

Vector4& Vector4::operator/=(const Vector4& other) {
	return Divide(other);
}

Vector4& Vector4::operator*=(const float& scalar) {
	return Multiply(scalar);
}

Vector4& Vector4::operator/=(const float& scalar) {
	return Divide(scalar);
}

bool Vector4::operator==(const Vector4& other) {
	return x == other.x && y == other.y;
}

bool Vector4::operator!=(const Vector4& other) {
	return !(*this == other);
}
