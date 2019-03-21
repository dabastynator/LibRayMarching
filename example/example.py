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
			LibRayMarchingVector(x = 4.5, y = -14, z = 4),
			LibRayMarchingVector(x = -0.2, y = 1, z = -0.2),
			LibRayMarchingVector(x = 0, y = 0, z = 1), math.pi*20/180);

	def BuildScene(self):
		print ("Create light")
		self.Scene.AddLight(LibRayMarchingVector(3, 3, 25), LibRayMarchingVector(1, 1, 1));

		print ("Create sphere")
		Sphere = self.Wrapper.CreateSphere(1);
		Sphere.SetMaterial(LibRayMarchingMaterial(
			Red = 0.6, 
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Sphere.Translate(LibRayMarchingVector(x = 0, y = 0, z = 2));
		self.Scene.AddPrimitive(Sphere);

		print ("Create box")
		Box = self.Wrapper.CreateBox(
			LibRayMarchingVector(x = 1, y = 1, z = 1)
		);
		Box.SetMaterial(LibRayMarchingMaterial(
			Blue = 0.6,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Box.Translate(LibRayMarchingVector(x = 3, y = 0, z = 2));
		self.Scene.AddPrimitive(Box);

		print ("Create capsule")
		Capsule = self.Wrapper.CreateCapsule(
			0.5,
			LibRayMarchingVector(x = -0.5, y = -0.5, z = -0.5),
			LibRayMarchingVector(x = 0.5, y = 0.5, z = 0.5)
		);
		Capsule.SetMaterial(LibRayMarchingMaterial(
			Green = 0.6,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Capsule.Translate(LibRayMarchingVector(x = 6, y = 0, z = 2));
		self.Scene.AddPrimitive(Capsule);

		print ("Create cylinder")
		Cylinder = self.Wrapper.CreateCylinder(1, 2);
		Cylinder.SetMaterial(LibRayMarchingMaterial(
			Red = 0.6, Green = 0.6,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Cylinder.Translate(LibRayMarchingVector(x = 0, y = -3, z = 2));		
		self.Scene.AddPrimitive(Cylinder);

		print ("Create torus")
		Torus = self.Wrapper.CreateTorus(0.7, 0.3);
		Torus.SetMaterial(LibRayMarchingMaterial(
			Blue = 0.6, Green = 0.6,
			Ambient = 0.3,
			Diffuse = 1,
			Specular = 1,
			SpecularAlpha = 15));
		Torus.Rotate(LibRayMarchingVector(x = 1, y = 0, z = 0), math.pi/2);
		Torus.Translate(LibRayMarchingVector(x = 3, y = -3, z = 2));		
		self.Scene.AddPrimitive(Torus);

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

	def RenderPixel(self):
		print ("Render scene")
		Pixel = self.Scene.RenderPixel(150, 90);
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
		#img.save('ray_marching.png')
		img.show()

def main():
	RM = RayMarching(300, 200);
	RM.BuildScene();
	RM.Render();
	

if __name__ == "__main__":
	try:
		main()
	except ELibRayMarchingException as e:
		print(e)
