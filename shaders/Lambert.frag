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
in vec3 pos_world;
in vec3 normal_world;
out vec4 color;
uniform vec3 light_world;
uniform vec3 light_color=vec3(1,1,1);
uniform vec3 material_color=vec3(1,1,1);
uniform float light_intensity=1.0;
void main(){
  vec3 fragToLight=light_world-pos_world;
  vec3 resColor=light_color*material_color;
  float diffuseFactor=dot(normalize(normal_world),normalize(fragToLight));
  color=vec4(resColor*light_intensity*diffuseFactor,1);
}