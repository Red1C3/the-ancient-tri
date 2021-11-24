#include <Texture.h>
using namespace tat;
using namespace sf;
using namespace gl;
Texture::Texture(const char *path)
{
    Image image;
    if (!image.loadFromFile(path))
    {
        assert(0);
    }
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, image.getSize().x, image.getSize().y,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, image.getPixelsPtr());
    assert(glGetError() == 0);
}
GLuint Texture::getID()
{
    return id;
}