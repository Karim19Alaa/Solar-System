#pragma once

#include <CelestialBody.h>

class Planet: public CelestialBody{
    protected:
        float orbitRadius, orbitVelocity;
        float orbitAngle;
    public:
        Planet(float radius, float orbitRadius, float spinVelocity, float orbitVelocity, float spinAngle, float orbitAngle, float color[3]);
        void draw() override;
        void update() override;
};