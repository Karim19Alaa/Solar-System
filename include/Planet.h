#pragma once

#include <CelestialBody.h>

class Planet: public CelestialBody{
    public:
        Planet(float radius, float orbitRadius, float spinVelocity, float orbitVelocity, float axisAngle, float orbitAngle, float color[3]);
        void draw() override;
        void update() override;
};