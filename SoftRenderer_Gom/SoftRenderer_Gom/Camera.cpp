#include "pch.h"
#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Render()
{
	//Entity::Render();
	static Matrix3x3 matrixT, matrixR, matrixS;

	MatrixIdentity(matrix);
	MatrixTranslation(matrixT, -position.x, -position.y);
	MatrixRotationDir(matrixR, -rotation);
	MatrixScale(matrixS, scale.x, scale.y);
	matrix = matrixT * matrixR * matrixS;
}
