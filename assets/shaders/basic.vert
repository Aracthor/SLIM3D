#version 300 es

layout (location = 0) in vec4 vPosition;

int	main()
{
    gl_Position = vPosition;
}
