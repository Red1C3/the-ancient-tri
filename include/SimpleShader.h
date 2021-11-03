#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <Shader.h>
#define SIMPLE_SHADER SimpleShader::instance()
namespace tat
{
    class SimpleShader : public Shader
    {
    private:
        SimpleShader();
        GLuint VPLocation, modelLocation;

    public:
        class Vertex
        {
        public:
            glm::vec3 pos;
            glm::vec3 color;
            glm::vec2 uv;
        };
        static SimpleShader &instance();
        void setVP(glm::mat4 VP);
        void setModel(glm::mat4 model);
        GLuint createVAO(const std::vector<Vertex>& vertices,const std::vector<unsigned>& indices);
    };
}