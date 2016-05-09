#version 300 es

precision mediump float;

in vec4		color;
in vec2		textureCoord;

uniform sampler2D	texture;

out vec4	fragColor;

void	main()
{
    fragColor = color;
    fragColor *= texture2D(texture, textureCoord);
}
