#pragma once
#include "..\Maths\Vector.h"
#include "..\Maths\Matrix.h"

class Camera
{
public:
	Camera();
	~Camera();

	void InitProjectionMatrix(float angle, int width, int height, float near, float far);
	void InitOrthogonalMatrix(int width, int height, float near, float far);
	
	void Resize(int width, int height);
	void Move(Vector3 direction);
	void Rotate(Vector3 axis, float degrees);
	void NearPlane(float near);
	void FarPlane(float far);

	void SetPosition(Vector3 position);
	void SetTarget(Vector3 target);
	void SetAngle(float angle);

	Vector3 Up();
	Vector3 LookAtTarget();
	Vector3 GetPosition();
	Vector3 GetTarget();
	float GetAngle();

	Matrix4x4 GetViewMatrix();
	Matrix4x4 GetProjectionMatrix();
	Matrix4x4 GetOrthogonalMatrix();
private:
	Vector3 m_Position;
	Vector3 m_Target;
	Vector3 m_Up;

	float m_Angle;
	float m_Width;
	float m_Height;
	float m_Near;
	float m_Far;

	Matrix4x4 m_View;
	Matrix4x4 m_Projection;
	Matrix4x4 m_Orthogonal;

	void InitViewMatrix();
};

