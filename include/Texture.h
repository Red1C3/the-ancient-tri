#pragma once
#include <assert.h>
#include <SFML/Graphics/Image.hpp>
#include <glbinding/gl33/gl.h>
namespace tat{
    class Texture
    {
    private:
        gl::GLuint id;

    public:
        Texture(const char *path);
        gl::GLuint getID();
    };
}