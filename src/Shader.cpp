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
#include<Shader.h>
using namespace tat;
using namespace std;
using namespace gl;
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