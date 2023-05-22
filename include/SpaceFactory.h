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

SpaceFactory::SpaceFactory(/* args */)
{
}

CelestialBody *SpaceFactory::create(CelestialBodiesEnum body){
    CelestialBody *created = nullptr;
    switch (body)
    {
    case SUN:
    {
        float color[3] = {1, 1, 0};
        created = new Star(GL_LIGHT0, 20.0f, 1.0f, 0.0f, color);
        break;
    }


    case MERCURY:
    {
        float color[3] = {0.2, 0.2, 0.2};
        created = new Planet(3, 30, 3, 4.7, 0, 0, color);
        break;
    }


    case VENUS:
    {
        float color[3] = {112.0f / 255, 109.0f / 255, 135.0f / 255};
        created = new Planet(5, 40, 3, 3.5, 0, 0, color);
        break;
    }



    case EARTH:
    {
        float color[3] = {0, 50.0f / 255, 200.0f / 255};
        CompositePlanet *cp = new CompositePlanet(6, 50, 3, 2.98, 0, 0, color);
        float moonColor[3] = {0.3, 0.3, 0.3};

        cp->addSurrounding(new Planet(2, 9, 2, 1, 0, 0, moonColor));
        created = cp;
        
        break;
    }


    case MARS:
    {
        float color[3] = {200.0f/250, 0, 0};
        created = new Planet(4.5, 60, 3, 2.41, 0, 0, color);
        break;
    }


    case JUPYTER:
    {
        float color[3] = {200.0f/250, 0, 0.4};
        created = new Planet(12, 80, 3, 1.31, 0, 0, color);
        break;
    }


    case SATURNE:
    {
        float color[3] = {0, 0.6, 0.4};
        CompositePlanet *cp = new CompositePlanet(10, 120, 3, 0.97, 0, 0, color);
        float moonColor[3] = {0.3, 0.3, 0.3};
        int n = 10;
        for(int i = 0; i < n; i++){
            cp->addSurrounding(new Planet(1, 15, 2, 1, 0, 360 * i / n, moonColor));
        }
        for(int i = 0; i < n; i++){
            cp->addSurrounding(new Planet(1, 13, 2, 1, 0, 360 * i / n - 18, moonColor));
        }
        for(int i = 0; i < n; i++){
            cp->addSurrounding(new Planet(1, 17, 2, 1, 0, 360 * i / n + 18, moonColor));
        }
        created = cp;
        break;
    }

    case URANUS:
    {
        float color[3] = {0.2, 0.1, 0.9};
        created = new Planet(8, 150, 3, 0.68, 0, 0, color);
        break;
    }

    case NEPTUNE:
    {
        float color[3] = {0, 0.5, 0.9};
        created = new Planet(7, 170, 3, 0.54, 0, 0, color);
        break;
    }

    default:
        break;
    }
    return created;
}


SpaceFactory::~SpaceFactory()
{
}
