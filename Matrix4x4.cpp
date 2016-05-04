#include "Matrix4x4.h"

const Matrix4x4 Matrix4x4::Identity = Matrix4x4(1.0f);
const Matrix4x4 Matrix4x4::Zero = Matrix4x4(0.0f);

Matrix4x4::Matrix4x4() {
	for (int i = 0; i < 4 * 4; i++)
		elements[i] = 0;
}

Matrix4x4::Matrix4x4(float num) {
	for (int i = 0; i < 4 * 4; i++)
		elements[i] = 0;
	elements[0 + 0 * 4] = num;
	elements[1 + 1 * 4] = num;
	elements[2 + 2 * 4] = num;
	elements[3 + 3 * 4] = num;
}

Matrix4x4::Matrix4x4(const float nums[4 * 4]) {
	for (int i = 0; i < 4 * 4; i++)
		elements[i] = nums[i];
}

Matrix4x4::Matrix4x4(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33) {
	elements[0] = n00;
	elements[1] = n01;
	elements[2] = n02;
	elements[3] = n03;
	elements[4] = n10;
	elements[5] = n11;
	elements[6] = n12;
	elements[7] = n13;
	elements[8] = n20;
	elements[9] = n21;
	elements[10] = n22;
	elements[11] = n23;
	elements[12] = n30;
	elements[13] = n31;
	elements[14] = n32;
	elements[15] = n33;
}

Matrix4x4::Matrix4x4(Vector3 v1, Vector3 v2, Vector3 v3, Vector3 v4) {
	elements[0] = v1.x;
	elements[1] = v1.y;
	elements[2] = v1.z;
	elements[3] = 0;
	elements[4] = v2.x;
	elements[5] = v2.y;
	elements[6] = v2.z;
	elements[7] = 0;
	elements[8] = v3.x;
	elements[9] = v3.y;
	elements[10] = v3.z;
	elements[11] = 0;
	elements[12] = v4.x;
	elements[13] = v4.y;
	elements[14] = v4.z;
	elements[15] = 0;
}

Matrix4x4::Matrix4x4(Vector4 v1, Vector4 v2, Vector4 v3, Vector4 v4) {
	elements[0] = v1.x;
	elements[1] = v1.y;
	elements[2] = v1.z;
	elements[3] = v1.w;
	elements[4] = v2.x;
	elements[5] = v2.y;
	elements[6] = v2.z;
	elements[7] = v2.w;
	elements[8] = v3.x;
	elements[9] = v3.y;
	elements[10] = v3.z;
	elements[11] = v3.w;
	elements[12] = v4.x;
	elements[13] = v4.y;
	elements[14] = v4.z;
	elements[15] = v4.w;
}

Matrix4x4::~Matrix4x4() { }

Matrix4x4& Matrix4x4::Add(const Matrix4x4& other) {
	for (int i = 0; i < 4 * 4; i++)
		elements[i] += other.elements[i];
	return *this;
}

Matrix4x4& Matrix4x4::Subtract(const Matrix4x4& other) {
	for (int i = 0; i < 4 * 4; i++)
		elements[i] -= other.elements[i];
	return *this;
}

Matrix4x4& Matrix4x4::Multiply(const Matrix4x4& other) {
	Matrix4x4 result;

	float x = elements[0];
	float y = elements[1];
	float z = elements[2];
	float w = elements[3];

	result.elements[0] = (other.elements[0] * x) + (other.elements[4] * y) + (other.elements[8] * z) + (other.elements[12] * w);
	result.elements[1] = (other.elements[1] * x) + (other.elements[5] * y) + (other.elements[9] * z) + (other.elements[13] * w);
	result.elements[2] = (other.elements[2] * x) + (other.elements[6] * y) + (other.elements[10] * z) + (other.elements[14] * w);
	result.elements[3] = (other.elements[3] * x) + (other.elements[7] * y) + (other.elements[11] * z) + (other.elements[15] * w);
	// Repeat for all the other rows
	x = elements[4];
	y = elements[5];
	z = elements[6];
	w = elements[7];
	result.elements[4] = (other.elements[0] * x) + (other.elements[4] * y) + (other.elements[8] * z) + (other.elements[12] * w);
	result.elements[5] = (other.elements[1] * x) + (other.elements[5] * y) + (other.elements[9] * z) + (other.elements[13] * w);
	result.elements[6] = (other.elements[2] * x) + (other.elements[6] * y) + (other.elements[10] * z) + (other.elements[14] * w);
	result.elements[7] = (other.elements[3] * x) + (other.elements[7] * y) + (other.elements[11] * z) + (other.elements[15] * w);
	x = elements[8];
	y = elements[9];
	z = elements[10];
	w = elements[11];
	result.elements[8] = (other.elements[0] * x) + (other.elements[4] * y) + (other.elements[8] * z) + (other.elements[12] * w);
	result.elements[9] = (other.elements[1] * x) + (other.elements[5] * y) + (other.elements[9] * z) + (other.elements[13] * w);
	result.elements[10] = (other.elements[2] * x) + (other.elements[6] * y) + (other.elements[10] * z) + (other.elements[14] * w);
	result.elements[11] = (other.elements[3] * x) + (other.elements[7] * y) + (other.elements[11] * z) + (other.elements[15] * w);
	x = elements[12];
	y = elements[13];
	z = elements[14];
	w = elements[15];
	result.elements[12] = (other.elements[0] * x) + (other.elements[4] * y) + (other.elements[8] * z) + (other.elements[12] * w);
	result.elements[13] = (other.elements[1] * x) + (other.elements[5] * y) + (other.elements[9] * z) + (other.elements[13] * w);
	result.elements[14] = (other.elements[2] * x) + (other.elements[6] * y) + (other.elements[10] * z) + (other.elements[14] * w);
	result.elements[15] = (other.elements[3] * x) + (other.elements[7] * y) + (other.elements[11] * z) + (other.elements[15] * w);
	return *this;
}

Vector4 Matrix4x4::Multiply(const Vector4& other) {
	Vector4 result;
	result.x = elements[0] * other.x + elements[1] * other.y + elements[2] * other.z + elements[3] * other.w;
	result.y = elements[4] * other.x + elements[5] * other.y + elements[6] * other.z + elements[7] * other.w;
	result.z = elements[8] * other.x + elements[9] * other.y + elements[10] * other.z + elements[11] * other.w;
	result.w = elements[12] * other.x + elements[13] * other.y + elements[14] * other.z + elements[15] * other.w;
	return result;
}

Matrix4x4& Matrix4x4::Multiply(const float& num) {
	for (int i = 0; i < 4 * 4; i++)
		elements[i] *= num;
	return *this;
}

Matrix4x4 Matrix4x4::Transpose() {//XMMatrixTranspose
	return *this;
}

Matrix4x4 Matrix4x4::Inverse() {//XMMatrixInverse
	return *this;
}

float Matrix4x4::Determinant() {//XMMatrixDeterminant

	return 0;
}

Matrix4x4 operator+(Matrix4x4 left, const Matrix4x4& right) {
	return left.Add(right);
}

Matrix4x4 operator-(Matrix4x4 left, const Matrix4x4& right) {
	return left.Subtract(right);
}

Matrix4x4 operator*(Matrix4x4 left, const Matrix4x4& right) {
	return left.Multiply(right);
}

Vector4 operator*(Matrix4x4 left, const Vector4& right) {
	return left.Multiply(right);
}

Matrix4x4 operator*(Matrix4x4 left, const float& right) {
	return left.Multiply(right);
} 

bool Matrix4x4::operator==(const Matrix4x4& other) {
	for (int i = 0; i < 4 * 4; i++)
		if (elements[i] != other.elements[i]) return false;
	return true;
}

bool Matrix4x4::operator!=(const Matrix4x4& other) {
	return !(*this == other);
}