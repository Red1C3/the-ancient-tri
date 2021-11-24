#version 330
in vec3 pos_world;
in vec3 normal_world;
out vec4 color;
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
  vec3 resColor=light_color*material_color;
  float diffuseFactor=dot(normalize(normal_world),normalize(fragToLight));
  vec3 viewVec=normalize(pos_world-observer_world);
	vec3 halfWay=normalize(fragToLight-viewVec);
	float specFactor=pow(max(dot(halfWay,normalize(normal_world)),0.0),spec);
  color=vec4(resColor*light_intensity*diffuseFactor,1)*diffusePercentage+
    vec4(resColor*light_intensity,1)*ambientPercentage+
    vec4(resColor*light_intensity,1)*specFactor*specularPercentage;
}