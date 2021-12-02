/*
the-ancient-tri A low level OpenGL render engine
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
#include <optional>
#include <vector>
#include <glm/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
namespace tat
{
    class Mesh
    {
    private:
        static Assimp::Importer importer;
        std::vector<glm::vec3> pos;
        std::optional<std::vector<unsigned>> indices;
        std::optional<std::vector<glm::vec3>> normals;
        std::optional<std::vector<glm::vec3>> tangents;
        std::optional<std::vector<glm::vec3>> bitangents;
        std::optional<std::vector<glm::vec2>> uvs;

    public:
        Mesh(const char *path);
        std::vector<glm::vec3> getPos();
        std::vector<glm::vec3> getNormals();
        std::vector<glm::vec3> getTangents();
        std::vector<glm::vec3> getBitangents();
        std::vector<glm::vec2> getUVs();
        std::vector<unsigned> getIndices();
        unsigned getVerticesCount();
    };
}
