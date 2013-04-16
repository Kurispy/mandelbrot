#include <GL/glew.h>
#include <GL/gl.h> 
#include <GL/glu.h>
#include <GL/glut.h>

#include "glutwidget.hpp"
#include "shader_utils.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

unsigned int glutWidget::m_frame;
unsigned int glutWidget::m_program;               
unsigned int glutWidget::m_fragmentsh;
bool glutWidget::guide = 0;
int glutWidget::color = 1;
float glutWidget::cx = 0.5, glutWidget::cy = 0.0;
float glutWidget::scale = 3.0;
int glutWidget::itr = 300;
const float glutWidget::zoom_factor = 0.1;


/*
 Initializes GLUT context
 */
glutWidget::glutWidget(int argc, char** argv)
{
    
    m_frame = 0;
    glutInitWindowSize(glutWidget::m_width, glutWidget::m_height);
    glutInit(&argc,argv);
    glutInitDisplayString("samples rgb double depth");
    glutCreateWindow("Mandelbrot");
    glutMouseFunc(mouseHandler);     //what to call when user clicks or scrolls
    glutKeyboardFunc(keyDown);       //what to call when user presses a key
    glutKeyboardUpFunc(keyUp);       //what to call when user releases a key
    glutSpecialFunc(specialKeyDown); //what to call when user presses a special key
    glutSpecialFunc(specialKeyUp);   //what to call when user releases a special key
    
    //may need to use glutOverlayDisplayFunc() here
    
    glutDisplayFunc(render);         //what to call when window needs redrawing
    glutIdleFunc(update);            //what to call when no user input given
    initOpenGL();
}


/*
 Checks whether graphics driver supports all required OpenGL features
 */
void glutWidget::checkExtensions()
{
    //query some extensions to make sure they are present
    if(glewGetExtension("GL_ARB_shading_language_100") != GL_TRUE)
    {
        std::cout << "ERROR: Shading language extension not present." << std::endl;
    }
    if(glewGetExtension("GL_ARB_vertex_program") != GL_TRUE)
    {
        std::cout << "ERROR: Vertex program extension not present." << std::endl;
    }
    if(glewGetExtension("GL_ARB_vertex_shader") != GL_TRUE)
    {
        std::cout << "ERROR: Vertex shader extension not present." << std::endl;
    }
    if(glewGetExtension("GL_ARB_fragment_program") != GL_TRUE)
    {
        std::cout << "ERROR: Fragment program extension not present." << std::endl;
    }
    if(glewGetExtension("GL_ARB_fragment_shader") != GL_TRUE)
    {
        std::cout << "ERROR: Fragment shader extension not present." << std::endl;
    }
    if(glewGetExtension("GL_ARB_vertex_buffer_object") != GL_TRUE)
    {
        std::cout << "ERROR: VBO extension not present." << std::endl;
    }    
}



/*
 Initializes opengl states
 */
void glutWidget::initOpenGL()
{
    glewExperimental = GL_TRUE; 
    GLenum err = glewInit();                             //initialize GLEW - this enables us to use extensions
    if(err != GLEW_OK)
    {
        std::cout << "ERROR: Loading GLEW failed." << std::endl;
        exit(-1);
    }
    checkExtensions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);   //default "empty"/background color is set to white
    
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    
    
    makeShaders();          //load data of fragment and vertex programs/shaders - compile shaders
    
    srand(time(NULL));
    
    color = rand() % 100 + 1;
}


/*
    Redraws window contents
 */
void glutWidget::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     //clears color and depth bits of framebuffer
    
    
    if(guide)
    {
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f((0.9+cx)/scale, (-0.2+cy)/scale);    
        glVertex2f((1.4+cx)/scale, (-0.2+cy)/scale);
        glVertex2f((1.15+cx)/scale, (0.3+cy)/scale);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f((0.1+cx)/scale, (1.6+cy)/scale);    
        glVertex2f((0.5+cx)/scale, (1.6+cy)/scale);
        glVertex2f((0.5+cx)/scale, (2.0+cy)/scale);
        glVertex2f((0.1+cx)/scale, (2.0+cy)/scale);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 0.0, 0.0);
        for(int i = 0; i < 360; i++)
        {
            glVertex2f((cos((float) i * (3.14159265/180.0)) + cx + (-5.0)) / (3 * scale), (sin((float) i * (3.14159265/180.0)) + cy) / (3 *scale));
        }
        glEnd();
    }

    glUseProgram(m_program); //Enables fragment shader
    
    setUniform2f(m_program, "center", glutWidget::cx, glutWidget::cy); //passes parameters from main program to fragment shader
    setUniform1f(m_program, "scale", glutWidget::scale);
    setUniform1i(m_program, "itr", itr);
    setUniform1i(m_program, "color", color);
    
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex2f(-1, -1);
    glTexCoord2f(1, 0);
    glVertex2f(1, -1);
    glTexCoord2f(1, 1);
    glVertex2f(1, 1);
    glTexCoord2f(0, 1);
    glVertex2f(-1, 1);
    glEnd();
    
    glUseProgram(0); //Disables fragment shader
    
    
    
    glutSwapBuffers();  //swaps front and back buffer for double buffering
}


/*
 Handles user event: a mouse button was pressed
 */
void glutWidget::mouseHandler(int button, int state, int x, int y)
{
    if (state == GLUT_UP)
        return;
    
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    float zscale = (1 / zoom_factor);
    
    //Get distance from center
    float dx = (((float) x / (float) w) - 0.5);
    float dy = (((float) y / (float) h) - 0.5);
    
    switch(button)
    {
        case 0: //Left click
            
            break;
        case 2: //Right click
            
            break;
        case 3: //Scroll up
            scale *= 1 - zoom_factor;
            cx -= (dx * scale) / zscale;
            cy += (dy * scale) / zscale;
            break;
        case 4: //Scroll down
            scale *= 1 + zoom_factor;
            cx += dx * scale / zscale;
            cy -= dy * scale / zscale;
            break;
    }
}


/*
 Handles user event: a key was pressed
 */
void glutWidget::keyDown(unsigned char key, int, int) 
{  
    switch(key)
    {
        case 'q':
        case 27:
            stop(); //quit the main loop, exit program
            break;
        case 'c':
            //change color scheme
            color = rand() % 100 + 1;
            break;
        case 'h':
            //toggle guidance
            guide = !guide;
            break;
        case 'w':
            scale *= 1 - zoom_factor; //zoom in
            break;
        case 's':
            scale *= 1 + zoom_factor; //zoom out
            break;
    }
}


/*
 Handles user event: a key was released
 */
void glutWidget::keyUp(unsigned char key, int, int) 
{  
    
}


/*
 Handles user event: a special key was pressed
 */
void glutWidget::specialKeyDown(int key, int, int) 
{
    
}


/*
 Handles user event: a special key was released
 */
void glutWidget::specialKeyUp(int key, int, int) 
{  
    float zscale = (1 / zoom_factor);
    
    switch(key)
    {
        case GLUT_KEY_UP:
            cy -= (0.5 * scale) / zscale;
            break;
        case GLUT_KEY_DOWN:
            cy += (0.5 * scale) / zscale;
            break;
        case GLUT_KEY_LEFT:
            cx += (0.5 * scale) / zscale;
            break;
        case GLUT_KEY_RIGHT:
            cx -= (0.5 * scale) / zscale;
            break;
    }
}



/*
    Forces program to stop, cleans up, and exits
 */
void glutWidget::stop()
{
    //clean up shaders
        glDetachShader(m_program,m_fragmentsh);
    
        glDeleteProgram(m_program);
	glDeleteShader(m_fragmentsh);
    
    exit(0);
}

/*
    Reads in and compiles shader objects
 */
void glutWidget::makeShaders()
{
    m_program = glCreateProgram();

	char *shadercode = readShader("shaders/fragmentshader.frag");     //reads shader code (you can edit shader code with a text editor)
        m_fragmentsh = glCreateShader(GL_FRAGMENT_SHADER_ARB);
	glShaderSource(m_fragmentsh, 1, (const GLcharARB **)&shadercode,NULL);
	delete[] shadercode;
	glCompileShader(m_fragmentsh);  //compiles shader
	printInfoLog(m_fragmentsh);     //prints errors during shader compilation
    
	glAttachShader(m_program,m_fragmentsh);

	glLinkProgram(m_program);   //compiles fragment and vertex shader into a shader program
	printInfoLog(m_program);    //prints errors during program compilation
}



/*
 Starts the main loop
 */
void glutWidget::run()
{
    glutMainLoop();
}



/*
    Called whenever no user input given
 */
void glutWidget::update()
{
    m_frame++;
    glutPostRedisplay(); //marks window for redrawing
    setUniform2f(m_program, "center", glutWidget::cx, glutWidget::cy);
    setUniform1f(m_program, "scale", glutWidget::scale);
}



    
