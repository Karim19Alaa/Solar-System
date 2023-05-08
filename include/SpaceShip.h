#pragma once

#include <Drawable.h>
#include <Director.h>
#include <math.h>

class SpaceShip: public Drawable, public Director{
private:
    float x, z, angle;

public:
    SpaceShip(float x, float z, float angle);
    ~SpaceShip();
    void draw() override;
    void update() override;
    void pointCamera() override;

    void throttle();
    void reverse();

    void steerLeft();
    void steerRight();
};