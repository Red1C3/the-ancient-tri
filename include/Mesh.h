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
        std::optional<std::vector<glm::vec2>> uvs;

    public:
        Mesh(const char *path);
        std::vector<glm::vec3> &getPos();
        std::vector<glm::vec3> &getNormals();
        std::vector<glm::vec2> &getUVs();
        std::vector<unsigned> &getIndices();
        unsigned getVerticesCount();
    };
}
