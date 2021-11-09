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
vector<vec3> &Mesh::getPos()
{
    return pos;
}
vector<vec3> &Mesh::getNormals()
{
    assert(normals);
    return normals.value();
}
vector<vec2> &Mesh::getUVs()
{
    assert(uvs);
    return uvs.value();
}
vector<unsigned> &Mesh::getIndices()
{
    assert(indices);
    return indices.value();
}
unsigned Mesh::getVerticesCount(){
    return pos.size();
}