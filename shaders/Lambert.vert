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
#version 330
layout(location=0) in vec3 pos_model;
layout(location=1) in vec3 normal_model;
layout(location=2) in vec2 uv;
out vec3 pos_world;
out vec3 normal_world;
uniform mat4 VP,model;
void main(){
  pos_world=(model*vec4(pos_model,1)).xyz;
  normal_world=(model*vec4(normal_model,0)).xyz;
  gl_Position=VP*vec4(pos_world,1);
}