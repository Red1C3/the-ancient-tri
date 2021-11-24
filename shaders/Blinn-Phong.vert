#version 330
layout(location=0) in vec3 pos_model;
layout(location=1) in vec3 normal_model;
layout(location=2) in vec2 uv;
layout(location=3) in vec3 tangent_model;
layout(location=4) in vec3 bitangent_model;
out vec3 pos_world;
out vec3 normal_world;
uniform mat4 VP,model;
void main(){
  pos_world=(model*vec4(pos_model,1)).xyz;
  normal_world=(model*vec4(normal_model,0)).xyz;
  gl_Position=VP*vec4(pos_world,1);
}