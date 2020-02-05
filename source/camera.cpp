#include <algorithm>
#include <cmath>
#include "vector.h"
#include "camera.h"

using namespace LibRayMarching;

void Camera::SetScreen(int width, int height)
{
	m_ScreenSizeX = width;
	m_ScreenSizeY = height;
	m_ScreenMaxSize = std::max(width, height);
}

void Camera::SetViewPort(const Vector& eye, const Vector& dir, const Vector& up, double fov)
{
	m_Eye = eye;
	m_Dir = dir.normalized();
	m_Up = up.normalized();
	m_Right = m_Dir.cross(m_Up).normalized();
	m_DirectionComponent = (float) std::cos(fov);
	m_UpRightComponent = (float) std::sin(fov);
}

void Camera::CalculateRay(double x, double y, Vector& point, Vector& dir) const
{
	// xd and yd goes from -1 to 1
	float xd = 2 * (x - m_ScreenSizeX / 2) / (float) m_ScreenMaxSize;
	float yd = 2 * (m_ScreenSizeY / 2 - y) / (float) m_ScreenMaxSize;

	// Set ray start
	point = m_Eye;

	// Calculate ray direction
	Vector up_right = m_Up * yd + m_Right * xd;
	Vector r = m_Dir * m_DirectionComponent + up_right * m_UpRightComponent;
	dir = r.normalized();
}
