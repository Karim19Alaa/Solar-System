
#include <CompositePlanet.h>

CompositePlanet::CompositePlanet(float radius, float orbitRadius, float spinVelocity,
                 float orbitVelocity, float spinAngle, float orbitAngle, float color[3]): surroundings(),
                Planet(radius, orbitRadius, spinVelocity, orbitVelocity, spinAngle, orbitAngle, color)
{

}

void CompositePlanet::addSurrounding(Drawable *drawable){
    surroundings.push_back(drawable);
}

void CompositePlanet::addSurroundings(std::vector<Drawable *> &drawables){

    surroundings.insert(surroundings.end(), drawables.begin(), drawables.end());
}

void CompositePlanet::draw(){

    Planet::draw();

    glPushMatrix();
        glRotatef(orbitAngle, 0, 1, 0);
        glTranslatef(orbitRadius, 0, 0);
        for(auto& d: this->surroundings){
            d->draw();
        }
    glPopMatrix();
}

void CompositePlanet::update(){

    Planet::update();
    for(auto& d: this->surroundings){
        d->update();
    }
}

CompositePlanet::~CompositePlanet(){}