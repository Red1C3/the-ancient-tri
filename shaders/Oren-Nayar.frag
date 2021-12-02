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
in vec3 pos_normal;
in vec3 light_normal;
in vec3 observer_normal;
out vec4 color;
uniform vec3 light_color=vec3(1,1,1);
uniform vec3 material_color=vec3(1,1,1);
uniform float light_intensity=1.0;
uniform float roughness=0.2;
void main(){
  vec3 fragToLight=light_normal-pos_normal;
  vec3 fragToObserver=observer_normal-pos_normal;
  vec3 resColor=light_color*material_color;
  float thetaI=acos(dot(normalize(fragToLight),vec3(0,0,1))); 
  float thetaR=acos(dot(normalize(fragToObserver),vec3(0,0,1)));
  float phaiI=acos(dot(normalize(fragToLight.xy),vec2(1,0)));
  float phaiR=acos(dot(normalize(fragToObserver.xy),vec2(1,0)));
  float alpha=max(thetaI,thetaR);
  float beta=min(thetaI,thetaR);
  float A=1.0-(0.5*(pow(roughness,2)/(pow(roughness,2)+0.33)));
  float B=0.45*(pow(roughness,2)/(pow(roughness,2)+0.09));
  float diffuseFactor=cos(thetaI)*(A+B*max(0,cos(phaiR-phaiI))*sin(alpha)*tan(beta));
  color=vec4(resColor*diffuseFactor,1);
}