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
#include <Shader.h>
using namespace tat;
using namespace std;
using namespace gl;
Shader::Shader(const char *vertexShader, const char *fragmentShader, bool fromFile)
{
    vector<char> vertexShaderArray, fragmentShaderArray;
    const char *vertexShaderCode, *fragmentShaderCode;
    if (!fromFile)
    {
        vertexShaderCode = vertexShader;
        fragmentShaderCode = fragmentShader;
    }
    else
    {
        vertexShaderArray = readBinaryFile(vertexShader);
        fragmentShaderArray = readBinaryFile(fragmentShader);
        vertexShaderCode = vertexShaderArray.data();
        fragmentShaderCode = fragmentShaderArray.data();
    }
    {
        auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
        int shaderLength = vertexShaderArray.size();
        glShaderSource(vertexShader, 1, &vertexShaderCode, &shaderLength);
        glCompileShader(vertexShader);
        char infoLog[1024];
        glGetShaderInfoLog(vertexShader, 1024, nullptr, infoLog);
        printf("%s \n", infoLog);
        auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        shaderLength = fragmentShaderArray.size();
        glShaderSource(fragmentShader, 1, &fragmentShaderCode, &shaderLength);
        glCompileShader(fragmentShader);
        glGetShaderInfoLog(fragmentShader, 1024, nullptr, infoLog);
        printf("%s \n", infoLog);
        id = glCreateProgram();
        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);
        glLinkProgram(id);
        glGetProgramInfoLog(id, 1024, nullptr, infoLog);
        printf("%s \n", infoLog);
        glDetachShader(id, vertexShader);
        glDetachShader(id, fragmentShader);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }
    assert(glGetError() == 0);
}
void Shader::use()
{
    glUseProgram(id);
}
GLint Shader::getID()
{
    return id;
}