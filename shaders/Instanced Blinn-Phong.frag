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
#version 330
in vec3 pos_world;
in vec3 normal_world;
in vec2 uv_out;
out vec4 color;
uniform sampler2D albedo;
uniform int useAlbedo=0;
uniform vec3 light_world;
uniform vec3 observer_world;
uniform vec3 light_color=vec3(1,1,1);
uniform vec3 material_color=vec3(1,1,1);
uniform float light_intensity=1.0;
uniform float spec=16.0;
uniform float diffusePercentage=0.5;
uniform float ambientPercentage=0.1;
uniform float specularPercentage=0.4;
void main(){
  vec3 fragToLight=light_world-pos_world;
  vec3 resColor;
  if(useAlbedo==0)
    resColor=light_color*material_color;
  else
    resColor=light_color*texture(albedo,uv_out).xyz;
  float diffuseFactor=dot(normalize(normal_world),normalize(fragToLight));
  vec3 viewVec=normalize(pos_world-observer_world);
	vec3 halfWay=normalize(fragToLight-viewVec);
	float specFactor=pow(max(dot(halfWay,normalize(normal_world)),0.0),spec);
  color=vec4(resColor*light_intensity*diffuseFactor,1)*diffusePercentage+
    vec4(resColor*light_intensity,1)*ambientPercentage+
    vec4(resColor*light_intensity,1)*specFactor*specularPercentage;
}