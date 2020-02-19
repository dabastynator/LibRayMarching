# LibRayMarching
The LibRayMarching is a library that implements ray marching and rendering by Phong Shading. It supports scene handling and implements several primitives as well as grouping.

### Primitives
The library supports following primitives
- Sphere
- Box
- Plane
- Capsuel
- Torus
- Quaternion Julia Fractal
- Menger Sponge

### Grouping
Primitives can be merged into groups. Therefore a group supports folling merging method
- Unify all primitives
- Intersect all primitives
- Take first primitives and subtract all following primitives

### Materials
The user can specify a material for a primitive. The material supports following material properties
- Color
- Ambient, Diffuse, Specular and SpecularAlpha for Phong Shading
- Reflection
- Transparency
Primitives also support a glowing property. Set a glow color and intensity to blend a glowing near to the primitive.

### Language Bindings
The API is defined by and ACT xml. This allows powerfull binding generation for following languages
- C (dynamic and static)
- C++ (dynamic and static)
- Python3
- Pascal

### Python example
Following Python listing shows how to render a scene that contains a torus
```python
import LibRayMarching
from PIL import Image
import math

Width = 300;
Height = 200;
# LibRayMarching. access
Wrapper = LibRayMarching.Wrapper("libraymarching");
Scene = Wrapper.CreateRayMarching();
Scene.SetScreenSize(Width, Height);
Scene.SetViewport(
	LibRayMarching.Vector(0, -6, 2),
	LibRayMarching.Vector(0, 1, -0.35),
	LibRayMarching.Vector(0, 0, 1), math.pi*20/180);
Scene.SetBackground(LibRayMarching.Vector(0.1, 0.1, 0.1), 30, 40);
Scene.AddLight(LibRayMarching.Vector(20, -20, 25), LibRayMarching.Vector(1, 1, 1));
Torus = Wrapper.CreateTorus(1, 0.3);
Torus.SetMaterial(LibRayMarching.Material(
	Red = 1, Green = 0.5, Blue = 0.5,
	Ambient = 0.3,
	Diffuse = 0.5,
	Specular = 1,
	SpecularAlpha = 50));
Torus.SetGlow(LibRayMarching.Glow(Red = 1, Green = 0, Blue = 0., Intensity = 0.02))
Scene.AddPrimitive(Torus);
Plane = Wrapper.CreatePlane(LibRayMarching.Vector(0,0,-0.5),LibRayMarching.Vector(0,0,1))
Plane.SetMaterial(LibRayMarching.Material(
	Red = 0.5, Green = 0.5, Blue = 0.5,
	Ambient = 0,#.5,
	AmbientOcclusion = 5,
	Diffuse = 0.2,
	Specular = 0.2,
	SpecularAlpha = 15));
Scene.AddPrimitive(Plane);
Scene.RenderScene();
ColorBuffer = Scene.GetColorBuffer();

# Save image as png with PIL
Img = Image.new('RGB', (Width, Height))
Pixels = Img.load()
for i in range(Img.size[0]):    # For every col
	for j in range(Img.size[1]):    # For every row
		color = ColorBuffer[i + j * Img.size[0]];		
		Pixels[i,j] = (int(color.Red*255), int(color.Green*255), int(color.Blue*255))
Img.save('torus.png')
Img.show()
```

![](example/torus.png)

### Demo

This youtube video demonstrates features of LibRayMarching v1

[![LibRayMarching v1 Demo](https://img.youtube.com/vi/yYpzFb8Q8nE/0.jpg)](https://www.youtube.com/watch?v=yYpzFb8Q8nE)