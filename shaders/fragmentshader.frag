uniform vec2 center;
uniform float scale;
uniform int itr, color;

void main() 
{
    vec2 z, c;
    int r = color / 3,
        g = color / 5,
        b = color / 7;

    c.x = (gl_TexCoord[0].x - 0.5) * scale - center.x;
    c.y = (gl_TexCoord[0].y - 0.5) * scale - center.y;

    int i;
    float x, y;
    z = c;
    for(i = 0; i < itr; i++) 
    {
        x = (z.x * z.x - z.y * z.y) + c.x;
        y = 2.0 * z.y * z.x + c.y;

        if((x * x + y * y) > 4.0) //Fragment is not in the set
            break;
        z.x = x;
        z.y = y;
    }
    
    //  The color mapping for red, green, and blue is based on the sine, cosine, 
    //  and tangent (respectively) of the number of iterations it took to escape,
    //  plus a random variable, all taken to the power of the random variable
    //  divided by a specific number. If a fragment is in the set, it is colored
    //  black.
    gl_FragColor = vec4(i == itr ? 0.0 : pow(sin(float(i + color)) * float(itr) / float(itr), float(r)),
                        i == itr ? 0.0 : pow(cos(float(i + color)) * float(itr) / float(itr), float(g)),
                        i == itr ? 0.0 : pow(tan(float(i + color)) * float(itr) / float(itr), float(b)),
                        1.0);
}