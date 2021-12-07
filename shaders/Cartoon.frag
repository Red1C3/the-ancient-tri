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
uniform vec3 light_world;
uniform vec3 observer_world;
uniform vec3 light_color=vec3(0.8,0.8,0.8);
uniform vec3 material_color=vec3(1,1,1);
uniform float light_intensity=1.0;
uniform float spec=64.0;
uniform float transition_start_angle=radians(75); 
uniform float transition_end_angle=radians(77);   
uniform float transition_start_percentage=1.0;   
uniform float transition_end_percentage=0.2;
uniform float spec_start_fac=1.0;
uniform float spec_end_fac=1.0;
uniform float spec_end_percentage=0.85;
uniform int useAlbedo=0;
uniform sampler2D albedo;
float linearInterpolate(float x,float x1,float x2,float y1,float y2){
  float m=(y2-y1)/(x2-x1);
  float c=y1-m*x1;
  return m*x+c;
}
float calculateDiffusePercentage(float angle){
  if(angle>radians(90)){
    return 0.0;
  }
  if(angle<transition_start_angle){
    return transition_start_percentage;
  }
  else if(angle>transition_end_angle){
    return transition_end_percentage;
  }else{
    return linearInterpolate(angle,
    transition_start_angle,
    transition_end_angle,
    transition_start_percentage,
    transition_end_percentage
    );
  }
}
float calculateSpec(float factor){
  if (factor<0.1)
    return 0.0;
  if(factor<0.2)
    return linearInterpolate(factor,0.1,0.2,0,spec_end_fac);
  return spec_end_fac;
}
void main(){
  vec3 resColor;
  if(useAlbedo==0)
    resColor=light_color*material_color;
  else
    resColor=light_color*texture(albedo,uv_out).xyz;
  vec3 fragToLight=normalize(light_world-pos_world);
  float angleF2LN=acos(dot(normalize(normal_world),fragToLight));
  float diffuseFac=calculateDiffusePercentage(angleF2LN);
  vec3 viewVec=normalize(pos_world-observer_world);
	vec3 halfWay=normalize(fragToLight-viewVec);
	float specFac=pow(max(dot(halfWay,normalize(normal_world)),0.0),spec);
	specFac=calculateSpec(specFac);
  color=vec4(resColor*(diffuseFac*0.6+specFac*0.1+0.3),1);
}

