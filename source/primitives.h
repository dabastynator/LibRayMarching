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

		public:

			enum Type {ptSphere, ptBox, ptPlane, ptCapsule, ptCylinder, ptTorus,
				ptMengerSonge, ptQuaternion};

			void IdentityPosition ();

			void Translate (const Vector& vTranslation);

			void Rotate (const Vector& vAxis, const double dRadian);

			void Scale (const Vector& vScale);

			void SetMaterial (const Material& Material);

			Material* GetMaterial() { return &m_Material; };

			virtual Type GetType () = 0;

			virtual void Initialize() {};

			virtual double SignedDistance (const Vector& vPoint) const = 0;
			
	};

	typedef std::shared_ptr<Primitive> PrimitivePtr;

	class Sphere: public virtual Primitive
	{

		private:

			double m_Radius;

		public:

			Sphere(double radius): m_Radius(radius) {};

			double GetRadius () { return m_Radius; };

			void SetRadius (const double dRadius) { m_Radius = dRadius; };

			Type GetType () { return Type::ptSphere; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;

	};

	typedef std::shared_ptr<Sphere> SpherePtr;

	class Capsule: public virtual Primitive
	{

		private:

			double m_Radius;

			Vector m_Point1, m_Point2, m_P1P2;

			double m_Length;

		public:

			Capsule(double radius): m_Radius(radius) {};

			double GetRadius () { return m_Radius; };

			void SetRadius (const double dRadius) { m_Radius = dRadius; };

			void SetPoint1 (const Vector& vPoint1) { m_Point1 = vPoint1; };

			Vector GetPoint1 () { return m_Point1; };

			void SetPoint2 (const Vector& vPoint2) { m_Point2 = vPoint2; };

			Vector GetPoint2 () { return m_Point2; };

			Type GetType () { return Type::ptCapsule; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;

	};

	typedef std::shared_ptr<Capsule> CapsulePtr;

	class Box: public virtual Primitive
	{

		private:

			Vector m_Dimensions;

		public:

			Vector GetDimensions () { return m_Dimensions; };

			void SetDimensions (const Vector& vDimensions) { m_Dimensions = vDimensions; };

			Type GetType () { return Type::ptBox; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;
	};

	typedef std::shared_ptr<Box> BoxPtr;

	class Plane: public virtual Primitive
	{

		private:

			Vector m_Origin;

			Vector m_TransformedNormal;
			
			Vector m_Normal;

		public:

			Vector GetNormal () { return m_Normal; };

			void SetNormal (const Vector& vNormal) { m_Normal = vNormal; };

			Type GetType () { return Type::ptPlane; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;

	};

	typedef std::shared_ptr<Plane> PlanePtr;


	class Cylinder: public virtual Primitive
	{

		private:

			double m_Radius;

			double m_Height;

		public:

			double GetRadius () { return m_Radius; };

			void SetRadius(double radius) {m_Radius = radius; };

			double GetHeight () { return m_Height; };

			void SetHeight(double height) {m_Height = height; };

			Type GetType () { return Type::ptCylinder; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;

	};

	typedef std::shared_ptr<Cylinder> CylinderPtr;

	class Torus: public virtual Primitive
	{

		private:

			double m_RadiusBig;

			double m_RadiusSmall;

		public:

			double GetRadiusBig () { return m_RadiusBig; };

			void SetRadiusBig(double radiusBig) {m_RadiusBig = radiusBig; };

			double GetRadiusSmall () { return m_RadiusSmall; };

			void SetRadiusSmall(double radiusSmall) {m_RadiusSmall = radiusSmall; };
			
			Type GetType () { return Type::ptTorus; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;

	};

	typedef std::shared_ptr<Torus> TorusPtr;

	class MengerSponge: public virtual Primitive
	{

		private:

			int m_SetpCount;

		public:

			double GetSetpCount () { return m_SetpCount; };

			void SetSetpCount(double setpcount) {m_SetpCount = setpcount; };

			Type GetType () { return Type::ptMengerSonge; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;

	};

	typedef std::shared_ptr<MengerSponge> MengerSpongePtr;

	class QuaternionFractal: public virtual Primitive
	{

		private:

			int m_Iterations;

			Quaternion m_Quaternion;

		public:

			double GetIterations () { return m_Iterations; };

			void SetIterations(double iterations) {m_Iterations = iterations; };

			Quaternion GetQuaternion () { return m_Quaternion; };

			void SetQuaternion(Quaternion quaternion) {m_Quaternion = quaternion; };

			Type GetType () { return Type::ptQuaternion; };

			void Initialize();

			double SignedDistance (const Vector& vPoint) const;

	};

	typedef std::shared_ptr<QuaternionFractal> QuaternionFractalPtr;

}
