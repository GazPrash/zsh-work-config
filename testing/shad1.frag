#version 120

uniform float time;
varying vec2 pos

void main()
{
    float r = abs(sin(time));
    float g = abs(sin(time + 1.0));
    float b = abs(sin(time + 2.0));
    gl_FragColor = vec4(r, g, b, 1.0);
    gl_FragCoord = vec4(pos.x, pos.y, 0., 1.0);
}
