#pragma once

#include <Drawable.h>

class CelestialBody: public Drawable {
protected:
    const float radius, orbitRadius, spinVelocity, orbitVelocity;
    float axisAngle, orbitAngle;
    float color[3], lightAmbient[3], lightDiffuse[3], lightPosition[3];
};