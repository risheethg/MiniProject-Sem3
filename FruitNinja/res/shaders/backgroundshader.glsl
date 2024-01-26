#shader vertex
#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 texCoords;

void main()
{
	gl_Position = vec4(aPos, 0.0, 1.0);
	texCoords = aTexCoords;
}

#shader fragment
#version 330 core

out vec4 FragColor;

in vec2 texCoords;

uniform sampler2D backgroundTexture;

void main()
{
	FragColor = texture(backgroundTexture, texCoords);
}