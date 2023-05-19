#pragma once

#include <CelestialBody.h>

class Star: public CelestialBody{
    private:
    GLenum lightID;
    public:
        Star(GLenum lightID, float radius, float spinVelocity, float axisAngle, float color[3]);
        void draw() override;
        void update() override;
};