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

// colors based on https://astronomy.stackexchange.com/questions/14032/color-of-planets
CelestialBody *SpaceFactory::create(CelestialBodiesEnum body){
    CelestialBody *created = nullptr;
    switch (body)
    {
    case SUN:
    {
        float color[3] = {0.9922, 0.7216, 0.07451};
        created = new Star(GL_LIGHT0, 20.0f, 1.0f, 0.0f, color);
        break;
    }


    case MERCURY:
    {
        float color[3] = {0.718, 0.722, 0.725};
        created = new Planet(3, 30, 3, 4.7 / 10, 0, 0, color);
        break;
    }


    case VENUS:
    {
        float color[3] = {1, 0.776, 0.286};
        created = new Planet(5, 40, 3, 3.5 / 10, 0, 0, color);
        break;
    }



    case EARTH:
    {
        float color[3] = {0.18, 0.42, 0.41};
        CompositePlanet *cp = new CompositePlanet(6, 50, 3, 2.98 / 10, 0, 0, color);
        float moonColor[3] = {0.96, 0.95, 0.84};

        cp->addSurrounding(new Planet(2, 9, 2, 0.5, 0, 0, moonColor));
        created = cp;
        
        break;
    }


    case MARS:
    {
        float color[3] = {0.6, 0.24, 0};
        created = new Planet(4.5, 60, 3, 2.41 / 10, 0, 0, color);
        break;
    }


    case JUPYTER:
    {
        float color[3] = {0.69, 0.5, 0.21};
        created = new Planet(12, 80, 3, 1.31 / 10, 0, 0, color);
        break;
    }


    case SATURNE:
    {
        float color[3] = {0.69, 0.56, 0.21};
        CompositePlanet *cp = new CompositePlanet(10, 120, 3, 0.97 / 10, 0, 0, color);
        float ringColor[3] = {0.6706, 0.3765, 0.2902};
        int n = 20;
        for(int i = 0; i < n; i++){
            cp->addSurrounding(new Planet(0.5, 15, 2, 0.5, 0, 360 * i / n, ringColor));
        }
        for(int i = 0; i < n; i++){
            cp->addSurrounding(new Planet(0.5, 13, 2, 0.5, 0, 360 * i / n - 9, ringColor));
        }
        for(int i = 0; i < n; i++){
            cp->addSurrounding(new Planet(0.5, 17, 2, 0.5, 0, 360 * i / n + 9, ringColor));
        }
        created = cp;
        break;
    }

    case URANUS:
    {
        float color[3] = {0.33, 0.5, 0.67};
        created = new Planet(8, 150, 3, 0.68 / 10, 0, 0, color);
        break;
    }

    case NEPTUNE:
    {
        float color[3] = {0.21, 0.41, 0.59};
        created = new Planet(7, 170, 3, 0.54 / 10, 0, 0, color);
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
