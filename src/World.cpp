#include <World.h>

World::World(): object(){}

void World::draw(){

    for(auto& d: this->object){
        d->draw();
    }
}

void World::tick(){

    for(auto& d: this->object){
        d->update();
    }
}

void World::addObject(Drawable *drawable){
    object.push_back(drawable);
}

void World::addObjects(std::vector<Drawable *> &drawables){
    object.insert(object.end(), drawables.begin(), drawables.end());
}

    
World::~World(){}