#pragma once

#include <vector>
#include <GL/freeglut.h>
#include <GL/glew.h>
#include <Drawable.h>
#include <Director.h>

class Renderer{
private:
    std::vector<Drawable> object;
    float xvmin, yvmin, width, height;
    Director *director;

public:
    Renderer(float xvmin, float yvmin, float width, float height, Director &director);

    void render();

    void addObject(Drawable&);
    void addObjects(std::vector<Drawable> &);
};