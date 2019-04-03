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

			double m_DistSinFactor;

			double m_DistSinSize;

			virtual double InternSignedDistance (const Vector& vPoint) const = 0;

		public:

			Primitive();

			void IdentityPosition ();

			void Translate (const Vector& vTranslation);

			void Rotate (const Vector& vAxis, const double dRadian);

			void Scale (const Vector& vScale);

			void SetMaterial (const Material& Material);

			Material* GetMaterial() { return &m_Material; };

			void SetDistortionSinus(double factor, double size);

			virtual PrimitiveType GetType () = 0;

			virtual void Initialize() {};

			double SignedDistance (const Vector& vPoint) const;
			
	};

	typedef std::shared_ptr<Primitive> PrimitivePtr;

	class Sphere: public virtual Primitive
	{

		private:

			double m_Radius;

		protected:

			double InternSignedDistance (const Vector& vPoint) const;

		public:

			Sphere(double radius): m_Radius(radius) {};

			double GetRadius () { return m_Radius; };

			void SetRadius (const double dRadius) { m_Radius = dRadius; };

			PrimitiveType GetType () { return ptSphere; };

			void Initialize();			

	};

	typedef std::shared_ptr<Sphere> SpherePtr;

	class Capsule: public virtual Primitive
	{

		private:

			double m_Radius;

			Vector m_Point1, m_Point2, m_P1P2;

			double m_Length;

		protected:

			double InternSignedDistance (const Vector& vPoint) const;			

		public:

			Capsule(double radius): m_Radius(radius) {};

			double GetRadius () { return m_Radius; };

			void SetRadius (const double dRadius) { m_Radius = dRadius; };

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

			double InternSignedDistance (const Vector& vPoint) const;

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

			double InternSignedDistance (const Vector& vPoint) const;

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

			double m_Radius;

			double m_Height;

		protected:

			double InternSignedDistance (const Vector& vPoint) const;

		public:

			double GetRadius () { return m_Radius; };

			void SetRadius(double radius) {m_Radius = radius; };

			double GetHeight () { return m_Height; };

			void SetHeight(double height) {m_Height = height; };

			PrimitiveType GetType () { return ptCylinder; };

			void Initialize();

	};

	typedef std::shared_ptr<Cylinder> CylinderPtr;

	class Torus: public virtual Primitive
	{

		private:

			double m_RadiusBig;

			double m_RadiusSmall;

		protected:

			double InternSignedDistance (const Vector& vPoint) const;

		public:

			double GetRadiusBig () { return m_RadiusBig; };

			void SetRadiusBig(double radiusBig) {m_RadiusBig = radiusBig; };

			double GetRadiusSmall () { return m_RadiusSmall; };

			void SetRadiusSmall(double radiusSmall) {m_RadiusSmall = radiusSmall; };
			
			PrimitiveType GetType () { return ptTorus; };

			void Initialize();
	};

	typedef std::shared_ptr<Torus> TorusPtr;

	class MengerSponge: public virtual Primitive
	{

		private:

			int m_SetpCount;

		protected:

			double InternSignedDistance (const Vector& vPoint) const;

		public:

			double GetSetpCount () { return m_SetpCount; };

			void SetSetpCount(double setpcount) {m_SetpCount = setpcount; };

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

			double InternSignedDistance (const Vector& vPoint) const;

		public:

			double GetIterations () { return m_Iterations; };

			void SetIterations(double iterations) {m_Iterations = iterations; };

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

			double InternSignedDistance (const Vector& vPoint) const;

		public:

			PrimitiveType GetType () { return ptGroup; };

			int GetCount() { return m_Primitives.size(); };

			void AddPrimitive(PrimitivePtr p) { m_Primitives.push_back(p); };

			PrimitivePtr GetPrimitive(int index) { return m_Primitives.at(index); };

			void SetCombineAction(CombineAction action) { m_CombineAction = action; };

			CombineAction GetCombineAction() { return m_CombineAction; };

			void Initialize();
	};

	typedef std::shared_ptr<PrimitiveGroup> PrimitiveGroupPtr;	

}
