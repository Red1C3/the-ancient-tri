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
layout(location=3) in vec3 tangent_model;
layout(location=4) in vec3 bitangent_model;
out vec3 pos_normal;
out vec3 light_normal;
out vec3 observer_normal;
uniform mat4 VP,model;
uniform vec3 light_world;
uniform vec3 observer_world;
void main(){
  vec3 pos_world=(model*vec4(pos_model,1)).xyz;
  vec3 normal_world=(model*vec4(normal_model,0)).xyz;
  gl_Position=VP*vec4(pos_world,1);
  vec3 tangent_world=(model*vec4(tangent_model,0)).xyz;
  vec3 bitangent_world=(model*vec4(bitangent_model,0)).xyz;
  mat3 TBN=mat3(tangent_world,bitangent_world,normal_world);
  mat3 iTBN=transpose(TBN);
  pos_normal=iTBN*pos_world;
  light_normal=iTBN*light_world;
  observer_normal=iTBN*observer_world;
}