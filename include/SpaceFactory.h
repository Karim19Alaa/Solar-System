#pragma once

#include <CelestialBody.h>
#include <Planet.h>
#include <CompositePlanet.h>
#include <Star.h>
#include <string>

#include <random>

class SpaceFactory
{
public:
    SpaceFactory();
    CelestialBody *create(CelestialBodiesEnum body);
    ~SpaceFactory();
};