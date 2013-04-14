#include <GL/glew.h>
#include <GL/gl.h> 
#include <GL/glu.h>
#include <GL/glut.h>

#include "glutwidget.hpp"
#include "shader_utils.hpp"
#include <iostream>

unsigned int glutWidget::m_frame;
unsigned int glutWidget::m_program;               
unsigned int glutWidget::m_fragmentsh;  
float glutWidget::cx = 0.0, glutWidget::cy = 0.0;
float glutWidget::scale = 2.2;
int glutWidget::itr = 70;
const float glutWidget::zoom_factor = 0.025;


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
    
    //Maybe scroll wheel zoom?
    
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
    glUseProgram(m_program); //Enables fragment shader
    
    setUniform1i(m_program, "itr", itr);
    
    
}


/*
    Redraws window contents
 */
void glutWidget::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     //clears color and depth bits of framebuffer

    
    setUniform2f(m_program, "center", glutWidget::cx, glutWidget::cy);
    setUniform1f(m_program, "scale", glutWidget::scale);
    
    
    
    glBegin(GL_QUADS);
    glVertex3f(-1, -1, 0);
    glVertex3f(1, -1, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(-1, 1, 0);
    glEnd();
    
    
   
    glutSwapBuffers();  //swaps front and back buffer for double buffering
}


/*
 Handles user event: a key was pressed
 */
void glutWidget::keyDown(unsigned char key, int, int) 
{  
    if(key == 'q'       //"q"
    || (int)key == 27) //escape key
    { 
        stop(); //quit the main loop, exit program
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



    
