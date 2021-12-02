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
#include <Mesh.h>
using namespace tat;
using namespace std;
using namespace glm;
using namespace Assimp;
Importer Mesh::importer;
Mesh::Mesh(const char *path)
{
    const aiScene *scene = importer.ReadFile(
        path,
        aiPostProcessSteps::aiProcess_FlipUVs | aiPostProcessSteps::aiProcess_Triangulate);
    assert(scene != nullptr);
    aiMesh *mesh = scene->mMeshes[0];
    assert(mesh != nullptr);
    pos.resize(mesh->mNumVertices);
    for (uint i = 0; i < pos.size(); ++i)
    {
        pos[i] = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
    }
    if (mesh->HasNormals())
    {
        normals = vector<vec3>();
        normals.value().resize(pos.size());
        for (uint i = 0; i < normals.value().size(); ++i)
        {
            normals.value()[i] = {
                mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z};
        }
    }
    if (mesh->HasTangentsAndBitangents())
    {
        tangents = vector<vec3>();
        tangents.value().resize(pos.size());
        bitangents = vector<vec3>();
        bitangents.value().resize(pos.size());
        for (uint i = 0; i < tangents.value().size(); ++i)
        {
            tangents.value()[i] = {
                mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z};
            bitangents.value()[i] = {
                mesh->mBitangents[i].x, mesh->mBitangents[i].y, mesh->mBitangents[i].z};
        }
    }
    if (mesh->HasTextureCoords(0))
    {
        uvs = vector<vec2>();
        uvs.value().resize(pos.size());
        for (uint i = 0; i < uvs.value().size(); ++i)
        {
            uvs.value()[i] = {
                mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y};
        }
    }
    if (mesh->HasFaces())
    {
        indices = vector<unsigned>();
        indices.value().resize(mesh->mNumFaces * 3);
        for (uint i = 0; i < indices.value().size(); i += 3)
        {
            indices.value()[i + 0] = mesh->mFaces[i / 3].mIndices[0];
            indices.value()[i + 1] = mesh->mFaces[i / 3].mIndices[1];
            indices.value()[i + 2] = mesh->mFaces[i / 3].mIndices[2];
        }
    }
}
vector<vec3> Mesh::getPos()
{
    return pos;
}
vector<vec3> Mesh::getNormals()
{
    assert(normals);
    return normals.value();
}
vector<vec3> Mesh::getTangents()
{
    assert(tangents);
    return tangents.value();
}
vector<vec3> Mesh::getBitangents()
{
    assert(bitangents);
    return bitangents.value();
}
vector<vec2> Mesh::getUVs()
{
    assert(uvs);
    return uvs.value();
}
vector<unsigned> Mesh::getIndices()
{
    assert(indices);
    return indices.value();
}
unsigned Mesh::getVerticesCount()
{
    return pos.size();
}