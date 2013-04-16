uniform vec2 center;
uniform float scale;
uniform int itr, color;

void main() 
{
    vec2 z, c;

    c.x = (gl_TexCoord[0].x - 0.5) * scale - center.x;
    c.y = (gl_TexCoord[0].y - 0.5) * scale - center.y;

    int i;
    float x, y;
    z = c;
    for(i = 0; i < itr; i++) 
    {
        x = (z.x * z.x - z.y * z.y) + c.x;
        y = 2 * z.y * z.x + c.y;

        if((x * x + y * y) > 4.0) 
            break;
        z.x = x;
        z.y = y;
    }

    gl_FragColor = vec4(i == itr ? 0.0 : pow((i + color) / float(itr), color % 3), i == itr ? 0.0 : pow((i + color) / float(itr), color % 5), i == itr ? 0.0 : pow((i + color) / float(itr), color % 7), 1.0);
}