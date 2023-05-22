#pragma once

#include <Drawable.h>

enum CelestialBodiesEnum{
    SUN, MERCURY, VENUS, EARTH, MARS, JUPYTER, SATURNE, URANUS, NEPTUNE
};

class CelestialBody: public Drawable {
protected:
    float radius, spinVelocity;
    float spinAngle;
    float color[3], lightAmbient[4], lightDiffuse[4], lightPosition[4];

    //TODO: add texture
};