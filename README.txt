ECS 175: Computer Graphics
UC Davis, Spring 2013
Mandelbrot Set Visualization
Christopher Chen
tech@ucdavis.edu

Requirements:
GLUT
GLEW
OpenGL
C++
cmake 


Overview:
Uses a fragment shader to render the Mandelbrot set.


Commands to create makefile + compile + run:

cmake .
make
./mandelbrot.x

Controls:

Translation         Arrow Keys
Zoom In             W
Zoom Out            S
Zoom In Cursor      Mouse Wheel Scroll Up
Zoom Out Cursor     Mouse Wheel Scroll Down
Enable Guidance     H
Change Colors       C
Quit                ESC, Q