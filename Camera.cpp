#include "Camera.h"

Camera::Camera() {
	m_Position = Vector3(0.0f, 0.0f, -10.0f);
	m_Target = Vector3(0.0f, 0.0f, 0.0f);
	m_Up = m_Position + Vector3(0.0f, 1.0f, 0.0f);

	m_Angle = 0;
	m_Width = 0;
	m_Height = 0;
	m_Near = 0;
	m_Far = 0;

	m_View = Matrix4x4::Identity;
	m_Projection = Matrix4x4::Identity;
	m_Orthogonal = Matrix4x4::Identity;
}

Camera::~Camera() { }

void Camera::InitProjectionMatrix(float angle, int width, int height, float near, float far) {

}

void Camera::InitOrthogonalMatrix(int width, int height, float near, float far) {

}

void Camera::Resize(int width, int height) {

}

void Camera::Move(Vector3 direction) {

}

void Camera::Rotate(Vector3 axis, float degrees) {

}

void Camera::NearPlane(float near) {

}

void Camera::FarPlane(float far) {

}

void Camera::SetPosition(Vector3 position) {

}

void Camera::SetTarget(Vector3 target) {

}

void Camera::SetAngle(float angle) {

}

Vector3 Camera::Up() {
	return Vector3();
}

Vector3 Camera::LookAtTarget() {
	return Vector3();
}

Vector3 Camera::GetPosition() {
	return Vector3();
}

Vector3 Camera::GetTarget() {
	return Vector3();
}

float Camera::GetAngle() {
	return 0;
}

Matrix4x4 Camera::GetViewMatrix() {
	return Matrix4x4();
}

Matrix4x4 Camera::GetProjectionMatrix() {
	return Matrix4x4();
}

Matrix4x4 Camera::GetOrthogonalMatrix() {
	return Matrix4x4();
}

void Camera::InitViewMatrix() {

}