#version 450

precision highp float;

layout(location = 0) in vec3 fragColor;
layout(location = 1) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 0) uniform UniformBufferObject {
    float scale;
    uint iter;
    vec2 center;
} v;
layout(binding = 1) uniform sampler2D texSampler;

void main() {
    vec2 z, c;

    c.x = 1.7777 * (fragTexCoord.x - 0.5) * v.scale - v.center.x;
    c.y = (fragTexCoord.y - 0.5) * v.scale - v.center.y;

    int i;
    z = c; 
    for(i=0; i<v.iter; i++) {
        float x = (z.x * z.x - z.y * z.y) + c.x;
        float y = (z.y * z.x + z.x * z.y) + c.y;

        if((x * x + y * y) > 4.0) break;
        z.x = x;
        z.y = y;
    }
    outColor = vec4(texture(texSampler, vec2((i == v.iter ? 0.0 : float(i)) / 100.0),0).rgb, 1.0f);
}