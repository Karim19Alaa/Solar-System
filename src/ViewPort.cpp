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
    director->pointCamera();
}

ViewPort::~ViewPort(){}