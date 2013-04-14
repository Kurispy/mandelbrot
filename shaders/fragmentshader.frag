uniform vec2 center;
uniform float scale;
uniform int itr;

void main() {
    vec2 z, c;

    c.x = (gl_FragCoord.x - 0.5);
    c.y = (gl_FragCoord.y - 0.5);

    int i;
    z = c;
    for(i=0; i<itr; i++) {
        float x = (z.x * z.x - z.y * z.y) + c.x;
        float y = (z.y * z.x + z.x * z.y) + c.y;

        if((x * x + y * y) > 4.0) break;
        z.x = x;
        z.y = y;
    }

    gl_FragColor = vec4(0.0, 0.0, (gl_FragCoord.x - 0.5)/500, 1.0);
}