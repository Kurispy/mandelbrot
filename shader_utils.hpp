char *readShader(const char * filename);
void printInfoLog(unsigned int obj);

//Functions for communication between the main program and the shaders
void setUniform1i(unsigned int m_program, const char *name, int value);
void setUniform1d(unsigned int m_program, const char *name, double value);
void setUniform2d(unsigned int m_program, const char *name, double value1, double value2);