#pragma once

#include <Drawable.h>
#include <Director.h>

class SpaceShip: public Drawable, public Director{
private:
//TODO: spaceship attribute

public:
    void draw() override;
    void update() override;
    void pointCamera() override;
};