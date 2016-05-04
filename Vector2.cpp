#include <iostream>
#include "Vector2.h"

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2& Vector2::Add(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::Subtract(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::Multiply(const Vector2& other) {
	x *= other.x;
	y *= other.y;
	return *this;
}

Vector2& Vector2::Divide(const Vector2& other) {
	x /= other.x;
	y /= other.y;
	return *this;
}

Vector2& Vector2::Multiply(const float& scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}

Vector2& Vector2::Divide(const float& scalar) {
	x /= scalar;
	y /= scalar;
	return *this;
}

Vector2 operator+(Vector2 left, const Vector2& right) {
	return left.Add(right);
}

Vector2 operator-(Vector2 left, const Vector2& right) {
	return left.Subtract(right);
}

Vector2 operator*(Vector2 left, const Vector2& right) {
	return left.Multiply(right);
}

Vector2 operator/(Vector2 left, const Vector2& right) {
	return left.Divide(right);
}

Vector2 operator*(Vector2 left, const float& right) {
	return left.Multiply(right);
}

Vector2 operator/(Vector2 left, const float& right) {
	return left.Divide(right);
}

Vector2& Vector2::operator+=(const Vector2& other) {
	return Add(other);
}

Vector2& Vector2::operator-=(const Vector2& other) {
	return Subtract(other);
}

Vector2& Vector2::operator*=(const Vector2& other) {
	return Multiply(other);
}

Vector2& Vector2::operator/=(const Vector2& other) {
	return Divide(other);
}

Vector2& Vector2::operator*=(const float& scalar) {
	return Multiply(scalar);
}

Vector2& Vector2::operator/=(const float& scalar) {
	return Divide(scalar);
}

bool Vector2::operator==(const Vector2& other) {
	return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) {
	return !(*this == other);
}

float Vector2::Magnitude() const {
	return sqrt(x * x + y * y);
}

Vector2 Vector2::Normalise() const {
	float length = Magnitude();
	return Vector2(x / length, y / length);
}

float Vector2::Distance(const Vector2& other) const {
	float a = x - other.x;
	float b = y - other.y;
	return sqrt(a * a + b * b);
}

float Vector2::Dot(const Vector2& other) const {
	return x * other.x + y * other.y;
}
