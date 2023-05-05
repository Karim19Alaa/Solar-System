#pragma once

#include <CelestialBody.h>

class Star: public CelestialBody{
    public:
        Star(float radius, float spinVelocity, float axisAngle, float color[3]);
        void draw() override;
        void update() override;
};