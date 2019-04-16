#pragma once

#include <vector>
#include <memory>
#include "vector.h"
#include "matrix.h"
#include "quaternion.h"
#include "types.h"

namespace LibRayMarching
{

	class Primitive
	{				

		protected:

			Matrix m_ModelToWorld;

			Matrix m_Inverse;

			Material m_Material;

			Distortion m_Distortion;

			float m_DistSinFactor;

			float m_DistSinSize;

			virtual float InternSignedDistance (const Vector& vPoint) const = 0;

		public:

			Primitive();

			void IdentityPosition ();

			void Translate (const Vector& vTranslation);

			void Rotate (const Vector& vAxis, const float dRadian);

			void Scale (const Vector& vScale);

			void SetMaterial (const Material& Material);

			Material* GetMaterial() { return &m_Material; };

			void SetDistortionSinus(float factor, float size);

			virtual PrimitiveType GetType () = 0;

			virtual void Initialize() {};

			float SignedDistance (const Vector& vPoint) const;
			
	};

	typedef std::shared_ptr<Primitive> PrimitivePtr;

	class Sphere: public virtual Primitive
	{

		private:

			float m_Radius;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			Sphere(float radius): m_Radius(radius) {};

			float GetRadius () { return m_Radius; };

			void SetRadius (const float dRadius) { m_Radius = dRadius; };

			PrimitiveType GetType () { return ptSphere; };

			void Initialize();			

	};

	typedef std::shared_ptr<Sphere> SpherePtr;

	class Capsule: public virtual Primitive
	{

		private:

			float m_Radius;

			Vector m_Point1, m_Point2, m_P1P2;

			float m_Length;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;			

		public:

			Capsule(float radius): m_Radius(radius) {};

			float GetRadius () { return m_Radius; };

			void SetRadius (const float dRadius) { m_Radius = dRadius; };

			void SetPoint1 (const Vector& vPoint1) { m_Point1 = vPoint1; };

			Vector GetPoint1 () { return m_Point1; };

			void SetPoint2 (const Vector& vPoint2) { m_Point2 = vPoint2; };

			Vector GetPoint2 () { return m_Point2; };

			PrimitiveType GetType () { return ptCapsule; };

			void Initialize();

	};

	typedef std::shared_ptr<Capsule> CapsulePtr;

	class Box: public virtual Primitive
	{

		private:

			Vector m_Dimensions;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			Vector GetDimensions () { return m_Dimensions; };

			void SetDimensions (const Vector& vDimensions) { m_Dimensions = vDimensions; };

			PrimitiveType GetType () { return ptBox; };

			void Initialize();
	};

	typedef std::shared_ptr<Box> BoxPtr;

	class Plane: public virtual Primitive
	{

		private:
			
			Vector m_Normal;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			Vector GetNormal () { return m_Normal; };

			void SetNormal (const Vector& vNormal) { m_Normal = vNormal; };

			PrimitiveType GetType () { return ptPlane; };

			void Initialize();
	};

	typedef std::shared_ptr<Plane> PlanePtr;


	class Cylinder: public virtual Primitive
	{

		private:

			float m_Radius;

			float m_Height;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			float GetRadius () { return m_Radius; };

			void SetRadius(float radius) {m_Radius = radius; };

			float GetHeight () { return m_Height; };

			void SetHeight(float height) {m_Height = height; };

			PrimitiveType GetType () { return ptCylinder; };

			void Initialize();

	};

	typedef std::shared_ptr<Cylinder> CylinderPtr;

	class Torus: public virtual Primitive
	{

		private:

			float m_RadiusBig;

			float m_RadiusSmall;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			float GetRadiusBig () { return m_RadiusBig; };

			void SetRadiusBig(float radiusBig) {m_RadiusBig = radiusBig; };

			float GetRadiusSmall () { return m_RadiusSmall; };

			void SetRadiusSmall(float radiusSmall) {m_RadiusSmall = radiusSmall; };
			
			PrimitiveType GetType () { return ptTorus; };

			void Initialize();
	};

	typedef std::shared_ptr<Torus> TorusPtr;

	class MengerSponge: public virtual Primitive
	{

		private:

			int m_SetpCount;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			int GetSetpCount () { return m_SetpCount; };

			void SetSetpCount(int setpcount) {m_SetpCount = setpcount; };

			PrimitiveType GetType () { return ptMengerSponge; };

			void Initialize();

	};

	typedef std::shared_ptr<MengerSponge> MengerSpongePtr;

	class QuaternionFractal: public virtual Primitive
	{

		private:

			int m_Iterations;

			Quaternion m_Quaternion;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			int GetIterations () { return m_Iterations; };

			void SetIterations(int iterations) {m_Iterations = iterations; };

			Quaternion GetQuaternion () { return m_Quaternion; };

			void SetQuaternion(Quaternion quaternion) {m_Quaternion = quaternion; };

			PrimitiveType GetType () { return ptQuaternion; };

			void Initialize();
	};

	typedef std::shared_ptr<QuaternionFractal> QuaternionFractalPtr;

	class PrimitiveGroup: public virtual Primitive
	{

		private:

			std::vector<PrimitivePtr> m_Primitives;

			CombineAction m_CombineAction;

		protected:

			float InternSignedDistance (const Vector& vPoint) const;

		public:

			PrimitiveType GetType () { return ptGroup; };

			size_t GetCount() { return m_Primitives.size(); };

			void AddPrimitive(PrimitivePtr p) { m_Primitives.push_back(p); };

			PrimitivePtr GetPrimitive(int index) { return m_Primitives.at(index); };

			void SetCombineAction(CombineAction action) { m_CombineAction = action; };

			CombineAction GetCombineAction() { return m_CombineAction; };

			void Initialize();
	};

	typedef std::shared_ptr<PrimitiveGroup> PrimitiveGroupPtr;	

}
