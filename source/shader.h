#pragma once

#include "primitives.h"
#include "camera.h"

namespace LibRayMarching
{

	class Shader
	{
		private:
			
			/*
			* Shader fields
			*/

			Camera m_Camera;
			std::vector<Light> m_Lights;
			std::vector<PrimitivePtr> m_Primitives;

			int m_MaxIteration = 300;
			double m_MaxDistance = 100;
			double m_MinDistance = 0.0001;
			double m_Epsilon = 0.005;
			int m_Bouncing = 10;
			Lightning m_Lightning;

			/*
			*  Calculation methods
			*/

			// Calculate color along ray by phong shading
			Vector PhongShading(const Vector& position, const Vector& ray);
			// Trace along given ray and calculate normal
			double Trace(const Vector& position, const Vector& ray, MarcheResult& result);
			// Ray marche along given ray and set result
			double RayMarche(const Vector& position, const Vector& ray, MarcheResult& result);
			// Find nearest primitive and set distance and material
			double GetDistance(const Vector& position, MarcheResult& result);

		public:

			Shader();

			Camera* GetCamera() { return &m_Camera; };
			Lightning* GetLightning() { return &m_Lightning; };

			void AddPrimitive(PrimitivePtr p) { m_Primitives.push_back(p); };
			PrimitivePtr GetPrimitive(int index) { return m_Primitives.at(index); };
			int GetPrimitiveCount() { return m_Primitives.size(); };
			void DeletePrimitive(int index){ m_Primitives.erase(m_Primitives.begin() + index); };
			
			void AddLight(Light light) { m_Lights.push_back(light); };
			Light GetLight(int index) { return m_Lights.at(index); };
			int GetLightCount() { return m_Lights.size(); };
			void DeleteLight(int index) { m_Lights.erase(m_Lights.begin() + index); };

			unsigned int RenderPixel(int x, int y);
	};


}
