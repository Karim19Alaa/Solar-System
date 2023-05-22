#include <ViewPort.h>

ViewPort::ViewPort(float xvmin, float yvmin, float width, float height, Director &director)
{
    this->xvmin = xvmin;
    this->yvmin = yvmin;
    this->width = width;
    this->height = height;
    this->director = &director;
}

void ViewPort::view(){
    glViewport(xvmin, yvmin, width, height);
    glClear(GL_DEPTH_BUFFER_BIT);
    director->pointCamera();
    
}
void ViewPort::update(float xmin, float ymin, float w, float h){
    this->xvmin = xmin;
    this->yvmin = ymin;
    this->width = w;
    this->height = h;
}

ViewPort::~ViewPort(){}