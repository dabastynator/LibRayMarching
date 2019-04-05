# LibRayMarching
The LibRayMarching is a library that implements ray marching. It supports scene handling and implements several primitives as well as grouping.

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

### Language Bindings
The API is defined by and ACT xml. This allows powerfull binding generation for following languages
- C
- C++
- Python3
- Pascal

### Python example
Following Python listing shows how to render a scene that contains a sphere
```python
from LibRayMarching import *
from PIL import Image
import math

Width = 300;
Height = 200;
# LibRayMarching access
Wrapper = LibRayMarchingWrapper("libraymarching");
Scene = Wrapper.CreateRayMarching();
Scene.SetScreenSize(Width, Height);
Scene.SetViewport(
	LibRayMarchingVector(x = 0, y = -6, z = 0),
	LibRayMarchingVector(x = 0, y = 1, z = 0),
	LibRayMarchingVector(x = 0, y = 0, z = 1), math.pi*20/180);
Scene.SetBackground(LibRayMarchingVector(x = 0.05, y = 0, z = 0.2), 30, 40);
Scene.AddLight(LibRayMarchingVector(0, -20, 25), LibRayMarchingVector(1, 1, 1));
Sphere = Wrapper.CreateSphere(1);
Sphere.SetMaterial(LibRayMarchingMaterial(
	Red = 0.5, Green = 0.1, Blue = 0.3,
	Ambient = 0.3,
	Diffuse = 1,
	Specular = 1,
	SpecularAlpha = 15));
Scene.AddPrimitive(Sphere);
Scene.RenderScene();
ColorBuffer = Scene.GetColorBuffer();

# Save image as png with PIL
Img = Image.new('RGB', (Width, Height))
Pixels = Img.load()
for i in range(Img.size[0]):    # for every col:
	for j in range(Img.size[1]):    # For every row
		color = ColorBuffer[i + j * Img.size[0]];		
		Pixels[i,j] = ((color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF) # set the colour accordingly
Img.save('sphere.png')
Img.show()
```

![](example/sphere.png)