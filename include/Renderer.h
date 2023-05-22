#pragma once

#include <World.h>
#include <ViewPort.h>
class Renderer
{
private:
    ViewPort *viewPort;
    World *world;

public:
    Renderer(World *w, ViewPort *v);

    void render();

    ~Renderer();
};


