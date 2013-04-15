uniform vec2 center;
uniform double scale;
uniform int itr;

void main() {
    vec2 z, c;

    c.x = (gl_TexCoord[0].x - 0.5) * scale - center.x;
    c.y = (gl_TexCoord[0].y - 0.5) * scale - center.y;

    int i;
    float x, y;
    z = c;
    for(i=0; i<itr; i++) {
        x = (z.x * z.x - z.y * z.y) + c.x;
        y = 2 * z.y * z.x + c.y;

        if((x * x + y * y) > 4.0) break;
        z.x = x;
        z.y = y;
    }

    gl_FragColor = vec4(0.0, (double(i == itr ? 0.0 : float(i)) + double(itr % i))/ double(itr), (double(i == itr ? 0.0 : float(i)) + double(itr % i))/ double(itr), 1.0);
}