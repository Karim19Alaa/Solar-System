#include <Renderer.h>

Renderer::Renderer(World *w, ViewPort *v)
{
    world = w;
    viewPort = v;
}

void Renderer::render(){
    this->viewPort->view();
    this->world->draw();


}

Renderer::~Renderer(){}