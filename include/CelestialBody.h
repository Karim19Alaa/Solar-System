#pragma once

#include <Drawable.h>

enum CelestialBodiesEnum{
    SUN, MERCURY, VENUS, EARTH, MARS, JUPYTER, SATURNE, URANUS, NEPTUNE
};

class CelestialBody: public Drawable {
protected:
    float radius, spinVelocity;
    float spinAngle;
    float light_Ambient_Diffuse[4];
};