#version 330
layout (location = 0) in vec3 pos;

out vec4 vCol;
uniform mat4 u_model;
uniform mat4 u_projection;
uniform mat4 u_view;

void main()
{
	gl_Position =  u_projection * u_view * u_model * vec4(pos, 1.0);
	vCol = vec4(clamp(pos, 0.0f, 1.0f), 1.0f);
}
