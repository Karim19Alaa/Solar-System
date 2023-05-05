#include <Renderer.h>

Renderer::Renderer(float xvmin, float yvmin, float width, float height, Director &director): object(){
    this->xvmin = xvmin;
    this->yvmin = yvmin;
    this->width = width;
    this->height = height;
    this->director = &director;
}

void Renderer::render(){

    glViewport(this->xvmin, this->yvmin, this->width, this->height);

    this->director->pointCamera();

    for(auto& d: this->object){
        d->draw();
    }
}

void Renderer::tick(){

    for(auto& d: this->object){
        d->update();
    }
}

void Renderer::addObject(Drawable *drawable){
    object.push_back(drawable);
}

void Renderer::addObjects(std::vector<Drawable *> &drawables){
    object.insert(object.end(), drawables.begin(), drawables.end());
}

    
Renderer::~Renderer(){}