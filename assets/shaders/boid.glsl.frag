#version 460 core

in vec3 vColor; // Interpolated color from vertex shader
out vec4 FragColor;

void main() {
    vec4 color = vec4(vColor, 1.0);
    FragColor = color; // Use calculated color
}