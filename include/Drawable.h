#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

class Drawable {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
};
