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

			int m_MaxIteration;
			float m_MaxDistance;
			float m_MinDistance;
			float m_Epsilon;
			int m_Bouncing;
			Lightning m_Lightning;

			/*
			*  Calculation methods
			*/

			Vector RefractRay(const Vector& ray, const Vector& normal, float refraction);

			void RayMarcheInside(const Primitive* primitive, const Vector& position, const Vector& ray, MarcheResult& result);			

			void RayMarchePrimitive(const Primitive* primitive, const Vector& position, const Vector& ray, MarcheResult& result);

			// Calculate color along ray by phong shading
			Vector PhongShading(const Vector& position, const Vector& ray, int bouncing);
			// Calculate the normal for given marche result
			void CalcNormal(Vector pos, Vector ray, MarcheResult& result);
			// Ray marche along given ray and set result
			float RayMarche(const Vector& position, const Vector& ray, MarcheResult& result, double max_distance);
			// Find nearest primitive and set distance and material
			float GetDistance(const Vector& position, MarcheResult& result);

		public:

			Shader();

			Camera* GetCamera() { return &m_Camera; };

			Lightning* GetLightning() { return &m_Lightning; };

			void AddPrimitive(PrimitivePtr p) { m_Primitives.push_back(p); };

			PrimitivePtr GetPrimitive(int index) { return m_Primitives.at(index); };

			size_t GetPrimitiveCount() { return m_Primitives.size(); };

			void DeletePrimitive(int index){ m_Primitives.erase(m_Primitives.begin() + index); };
			
			void AddLight(Light light) { m_Lights.push_back(light); };

			Light GetLight(int index) { return m_Lights.at(index); };

			size_t GetLightCount() { return m_Lights.size(); };
			
			void DeleteLight(int index) { m_Lights.erase(m_Lights.begin() + index); };

			Vector RenderPixel(float x, float y);

			void SetMaxBouncing(int bouncing) { m_Bouncing = bouncing; };
	};


}
