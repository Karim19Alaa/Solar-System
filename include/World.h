#pragma once

#include <vector>
#include <Drawable.h>
#include <Director.h>

class World{
private:
    std::vector<Drawable *> object;


public:
    World();

    void draw();
    void tick();

    void addObject(Drawable *);
    void addObjects(std::vector<Drawable *> &);

    ~World();
};