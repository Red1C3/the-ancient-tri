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
#include <glm/glm.hpp>
#include <Shader.h>
namespace tat
{
    class BRDFShader : public Shader
    {
    public:
        BRDFShader(const char *vertexShader, const char *fragmentShader, bool fromFile = true);
        class Vertex
        {
        public:
            glm::vec3 pos;
            glm::vec3 normal;
            glm::vec2 uv;
            glm::vec3 tangents;
            glm::vec3 bitangents;
        };
        static gl::GLuint createVAO(const std::vector<Vertex> &vertices, const std::vector<unsigned> &indices);
    };
}
