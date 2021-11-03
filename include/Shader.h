#pragma once
#include<GL/glew.h>
#include<assert.h>
#include<helpers.h>
namespace tat
{
    class Shader
    {
    protected:
        GLint id;
    public:
        Shader(const char *vertexShader, const char *fragmentShader, bool fromFile = true);
        void use();
    };
}