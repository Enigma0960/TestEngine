#pragma once
struct Vector2
{
	float x, y;

	Vector2();
	Vector2(float x, float y);

	Vector2& Add(const Vector2& other);
	Vector2& Subtract(const Vector2& other);
	Vector2& Multiply(const Vector2& other);
	Vector2& Divide(const Vector2& other);
	Vector2& Multiply(const float& scalar);
	Vector2& Divide(const float& scalar);

	friend Vector2 operator+(Vector2 left, const Vector2& right);
	friend Vector2 operator-(Vector2 left, const Vector2& right);
	friend Vector2 operator*(Vector2 left, const Vector2& right);
	friend Vector2 operator/(Vector2 left, const Vector2& right);
	friend Vector2 operator*(Vector2 left, const float& right);
	friend Vector2 operator/(Vector2 left, const float& right);

	Vector2& operator+=(const Vector2& other);
	Vector2& operator-=(const Vector2& other);
	Vector2& operator*=(const Vector2& other);
	Vector2& operator/=(const Vector2& other);
	Vector2& operator*=(const float& scalar);
	Vector2& operator/=(const float& scalar);

	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

	float Magnitude() const;
	Vector2 Normalise() const;
	float Distance(const Vector2& other) const;
	float Dot(const Vector2& other) const;
};

