#pragma once

#include <Drawable.h>

class CelestialBody: public Drawable {
protected:
    float radius, spinVelocity;
    float spinAngle;
    float color[3], lightAmbient[3], lightDiffuse[3], lightPosition[3];

    //TODO: add texture
};