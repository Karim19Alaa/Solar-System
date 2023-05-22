#pragma once

#include <Planet.h>
#include <vector>

class CompositePlanet: public Planet
{
private:
    std::vector<Drawable *> surroundings;
public:
    CompositePlanet(float radius, float orbitRadius, float spinVelocity,
                 float orbitVelocity, float spinAngle, float orbitAngle, float color[3]);

    void addSurrounding(Drawable *drawable);

    void addSurroundings(std::vector<Drawable *> &drawables);

    void draw() override;

    void update() override;


    ~CompositePlanet();
};
