#pragma once

#include <World.h>
#include <ViewPort.h>
class Renderer
{
private:
    /* data */
    ViewPort *viewPort;
    World *world;

public:
    Renderer(World *w, ViewPort *v);

    void render();

    ~Renderer();
};


