/*
the-ancient-tri an OpenGL legacy simulator

Copyright (C) 2021 Mohammad Issawi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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