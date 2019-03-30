'''++

Copyright (C) 2019 PrimeDevelopers

All rights reserved.

This file has been generated by the Automatic Component Toolkit (ACT) version 1.4.0.

Abstract: This is an autogenerated Python application that demonstrates the
 usage of the Python bindings of Ray Marching Library

Interface version: 0.9.0

'''


import os
import sys
import math
from LibRayMarching import *
from PIL import Image
import math

class RayMarching:

	def __init__(self, width, height):
		self.Wrapper = LibRayMarchingWrapper("../build/libraymarching");
		major, minor, micro = self.Wrapper.GetLibraryVersion();
		print("LibRayMarching version: {:d}.{:d}.{:d}".format(major, minor, micro));

		self.Scene = self.Wrapper.CreateRayMarching();
		print("Set size")
		self.Scene.SetScreenSize(width, height);
		self.Width = width;
		self.Height = height;

		print("Set viewport")
		self.Scene.SetViewport(
			LibRayMarchingVector(x = 6.5, y = -16, z = 4),
			LibRayMarchingVector(x = -0.3, y = 1, z = -0.2),
			LibRayMarchingVector(x = 0, y = 0, z = 1), math.pi*20/180);

	def BuildScene(self):
		print ("Create light")
		self.Scene.AddLight(LibRayMarchingVector(9, -20, 25), LibRayMarchingVector(1, 1, 1));
		
		print ("Create sphere")
		Sphere = self.Wrapper.CreateSphere(1);
		Sphere.SetMaterial(LibRayMarchingMaterial(
			Red = 0.5, Green = 0.1, Blue = 0.3,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Sphere.SetSinusDistortion(0.06, 0.6);
		Sphere.Translate(LibRayMarchingVector(x = 0, y = 0, z = 2));
		self.Scene.AddPrimitive(Sphere);
		
		print ("Create box")
		Box = self.Wrapper.CreateBox(
			LibRayMarchingVector(x = 0.5, y = 0.5, z = 0.5)
		);
		Box.SetMaterial(LibRayMarchingMaterial(
			Red = 0.5, Blue = 0.1, Green = 0.3,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Box.Translate(LibRayMarchingVector(x = 3, y = -3, z = 2));
		self.Scene.AddPrimitive(Box);

		print ("Create capsule")
		Capsule = self.Wrapper.CreateCapsule(
			0.5,
			LibRayMarchingVector(x = -0.5, y = -0.5, z = -0.5),
			LibRayMarchingVector(x = 0.5, y = 0.5, z = 0.5)
		);
		Capsule.SetMaterial(LibRayMarchingMaterial(
			Blue = 0.5, Green = 0.1, Red = 0.3,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Capsule.Translate(LibRayMarchingVector(x = 6, y = 0, z = 2));
		self.Scene.AddPrimitive(Capsule);

		print ("Create cylinder")
		Cylinder = self.Wrapper.CreateCylinder(1, 2);
		Cylinder.SetMaterial(LibRayMarchingMaterial(
			Green = 0.5, Red = 0.1, Blue = 0.3,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Cylinder.Translate(LibRayMarchingVector(x = 0, y = -3, z = 2));		
		self.Scene.AddPrimitive(Cylinder);

		print ("Create torus")
		Torus = self.Wrapper.CreateTorus(0.7, 0.3);
		Torus.SetMaterial(LibRayMarchingMaterial(
			Green = 1, Blue = 1, Red = 1,
			Ambient = 0.05,
			Diffuse = 0.1,
			Specular = 0.3,
			SpecularAlpha = 15,
			Reflection = 0.6));
		Torus.Rotate(LibRayMarchingVector(x = 1, y = 0, z = 0), math.pi/2);
		Torus.Translate(LibRayMarchingVector(x = 3, y = 0, z = 2));		
		self.Scene.AddPrimitive(Torus);

		print ("Create transparent sphere")
		Sphere = self.Wrapper.CreateSphere(1);
		Sphere.SetMaterial(LibRayMarchingMaterial(
			Blue = 0.5, Red = 0.1, Green = 0.3,
			Ambient = 0.1,
			Diffuse = 0.2,
			Specular = 0.4,
			SpecularAlpha = 15,
			Transparency = 0.5,
			Refraction = 1.33));
		Sphere.Translate(LibRayMarchingVector(x = 6, y = -3, z = 2));
		self.Scene.AddPrimitive(Sphere);
		
		print ("Create menger sponge")
		MengerSponge = self.Wrapper.CreateMengerSponge(3);
		MengerSponge.SetMaterial(LibRayMarchingMaterial(
			Green = 0.5, Blue = 0.1, Red = 0.3,
			Ambient = 0.3,
			Diffuse = 0.5,
			Specular = 0.4,
			SpecularAlpha = 15));
		MengerSponge.Translate(LibRayMarchingVector(x = 0, y = -6, z = 2));
		self.Scene.AddPrimitive(MengerSponge);

		print ("Create julia quaternion fractal")
		QuaternionFractal = self.Wrapper.CreateQuaternionFractal(10);
		QuaternionFractal.SetQuaternion(0.2, -0.4, 0, -0.6);
		QuaternionFractal.SetMaterial(LibRayMarchingMaterial(
			Green = 0.5, Blue = 0.1, Red = 0.5,
			Ambient = 0.3,
			Diffuse = 0.5,
			Specular = 0.4,
			SpecularAlpha = 15));
		QuaternionFractal.Translate(LibRayMarchingVector(x = 3, y = -6, z = 2));
		self.Scene.AddPrimitive(QuaternionFractal);
		
		GSphere = self.Wrapper.CreateSphere(1.25);
		GBox = self.Wrapper.CreateBox(
			LibRayMarchingVector(x = 1, y = 1, z = 1)
		);
		GCylinder = self.Wrapper.CreateCylinder(0.4, 100);
		GCylinder.Rotate(LibRayMarchingVector(x = 1, y = 0, z = 0), math.pi/2);
		GroupRCube = self.Wrapper.CreatePrimitiveGroup(LibRayMarchingGroupAction.Intersect);
		GroupRCube.AddPrimitive(GSphere);
		GroupRCube.AddPrimitive(GBox);

		GroupM = self.Wrapper.CreatePrimitiveGroup(LibRayMarchingGroupAction.Subtract);
		GroupM.AddPrimitive(GroupRCube);
		GroupM.AddPrimitive(GCylinder);
		GroupM.Translate(LibRayMarchingVector(x = 6, y = -6, z = 2));
		GroupM.SetMaterial(LibRayMarchingMaterial(
			Green = 0.5, Blue = 0.5, Red = 0.1,
			Ambient = 0.3,
			Diffuse = 0.5,
			Specular = 0.4,
			SpecularAlpha = 15));			
		self.Scene.AddPrimitive(GroupM);
		
		print ("Create pane")
		Plane = self.Wrapper.CreatePlane(
			LibRayMarchingVector(x = 0, y = 0, z = 0),
			LibRayMarchingVector(x = 0, y = 0, z = 1)
		);
		Plane.SetMaterial(LibRayMarchingMaterial(
			Red = 0.2, Green = 0.2, Blue = 0.2,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		self.Scene.AddPrimitive(Plane);

	def RenderPixel(self, x, y):
		print ("Render scene")
		Pixel = self.Scene.RenderPixel(x, y);
		print ("Pixelcolor is " + str(Pixel))


	def Render(self):
		print ("Render scene")
		self.Scene.RenderScene();

		print ("Get buffer")
		color_buffer = self.Scene.GetColorBuffer();
		print ("Buffer length " + str(len(color_buffer)))

		img = Image.new('RGB', (self.Width, self.Height))
		pixels = img.load()
		for i in range(img.size[0]):    # for every col:
			for j in range(img.size[1]):    # For every row
				color = color_buffer[i + j * img.size[0]];
				# print color;    		
				pixels[i,j] = ((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF) # set the colour accordingly
		img.save('ray_marching.png')
		img.show()

def main():
	RM = RayMarching(600, 400);
	RM.BuildScene();
	RM.RenderPixel(70, 300);
	RM.Render();
	

if __name__ == "__main__":
	try:
		main()
	except ELibRayMarchingException as e:
		print(e)
