#pragma once

#include "vector.h"

namespace LibRayMarching
{
	class Camera
	{
		private:

			int m_ScreenSizeX;
			int m_ScreenSizeY;

			int m_ScreenMaxSize;
			double m_DirectionComponent;
			double m_UpRightComponent;

			Vector m_Up;
			Vector m_Dir;
			Vector m_Eye;
			Vector m_Right;

		public:

			void SetScreen(int width, int height);

			int GetWidth() { return m_ScreenSizeX; };
			
			int GetHeight() { return m_ScreenSizeY; };

			void SetViewPort(const Vector& eye, const Vector& dir, const Vector& up, double fov);

			void CalculateRay(double x, double y, Vector& point, Vector& dir) const;
	};

}
