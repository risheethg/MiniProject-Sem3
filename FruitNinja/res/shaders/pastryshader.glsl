#shader vertex
#version 330 core

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;

uniform float uPosition;

void main()
{
    TexCoords = aTexCoords;    
    gl_Position = vec4(uPosition, 0.0, 0.0, 0.0);
}

#shader fragment 
#version 330 core
out vec4 FragColor;

in vec2 TexCoords;

uniform sampler2D texture_diffuse1;

void main()
{    
    FragColor = texture(texture_diffuse1, TexCoords);
}