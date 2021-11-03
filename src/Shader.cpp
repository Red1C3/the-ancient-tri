#include<Shader.h>
using namespace tat;
using namespace std;
Shader::Shader(const char *vertexShader, const char *fragmentShader, bool fromFile)
{
    vector<char> vertexShaderArray, fragmentShaderArray;
    const char *vertexShaderCode, *fragmentShaderCode;
    if(!fromFile){
        vertexShaderCode = vertexShader;
        fragmentShaderCode = fragmentShader;
    }else{
        vertexShaderArray = readBinaryFile(vertexShader);
        fragmentShaderArray = readBinaryFile(fragmentShader);
        vertexShaderCode = vertexShaderArray.data();
        fragmentShaderCode = fragmentShaderArray.data();
    }
    {
        auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
        glCompileShader(vertexShader);
        auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
        glCompileShader(fragmentShader);
        id = glCreateProgram();
        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);
        glLinkProgram(id);
        glDetachShader(id, vertexShader);
        glDetachShader(id, fragmentShader);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
    assert(glGetError() == 0);
}
void Shader::use(){
    glUseProgram(id);
}