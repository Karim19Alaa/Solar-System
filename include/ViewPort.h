#pragma once

#include <Director.h>
#include <GL/freeglut.h>

class ViewPort
{
private:
    /* data */
    float xvmin, yvmin, width, height;
    Director *director;
public:
    ViewPort(float xvmin, float yvmin, float width, float height, Director &director);
    void view();
    void update(int xmin, int ymin, int w, int h);
    ~ViewPort();
};
