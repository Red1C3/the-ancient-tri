# the-ancient-tri
A legacy OpenGL simulator for OpenGL 3.3, written in C++.

# ScreenShots
![BlinnPhong](snaps/Blinn-Phong-1.png)
![Lambert](snaps/Lambert-1.png)

## Why?
My Uni forces us to use legacy OpenGL (eww!), and I didn't want to learn it, so this project is supposed to be a modern boilerplate for the legacy one (it should run faster too)

## Can I use it as a renderer?
Let's say for a game or a simple graphics needing app, if you're not looking for great visuals, I guess it'll be enough, however, you still need to know the basics of modern OpenGL (at least the new stuff in 2.0 or later) since I'm not wrapping everything, some code still needs to be written with plain OpenGL (this may change in the future though)

## Features
- Import Meshes from disk with ``Mesh`` class (Assimp supported formats only)
- Pure Lambert lighting model
- Blinn-Phong lighting model
- User-defined Shaders can be added by extending ``Shader`` or ``BRDFShader`` class as needed

## Building
Using Meson, check dependencies first, build script is provided, it may not work on Windows, since it uses a Bash script, if it doesn't, write a similar batch script or whatever that works with you.

Note: if the root directory contains a file named ```main.cpp``` the build script will automatically build an executable alongside the dynamic library

## Dependencies:
- [SFML](https://www.sfml-dev.org/) (link against window and graphics modules)
- [glbinding](https://github.com/cginternals/glbinding)
- [GLM](https://github.com/g-truc/glm)
- [Assimp](https://github.com/assimp/assimp)

## Contribution
While I'm okay with it, I really suggest you not to, the project is not worth it.

## License
Under GPLv3, check [LICENSE](./LICENSE.md)

### Made with sick-of-college kittens