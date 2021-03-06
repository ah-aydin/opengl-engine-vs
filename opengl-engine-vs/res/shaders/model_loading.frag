#version 400 core

out vec4 FragColor;

in vec2 TexCoords;

struct Material
{
    sampler2D texture_diffuse1;
    sampler2D texture_diffuse2;
};

uniform Material material;

void main()
{
    FragColor = texture(material.texture_diffuse1, TexCoords) * texture(material.texture_diffuse2, TexCoords);
}