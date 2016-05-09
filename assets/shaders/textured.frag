#version 300 es

precision mediump float;

in vec3		position;
in vec2		textureCoord;

uniform sampler2D	texture;

out vec4	fragColor;

void	main()
{
    fragColor = vec4(1.0, 1.0, 1.0, 1.0);
    fragColor *= texture2D(texture, textureCoord);
}
