#version 330 core
out vec4 FragColor;

in vec2 v_TexCoord;
in float v_TexIndex;

uniform sampler2D u_Textures[2];

void main()
{
	int texIndex = int(v_TexIndex);
	vec4 texColor = texture(u_Textures[texIndex], v_TexCoord);
	FragColor = texColor;
}