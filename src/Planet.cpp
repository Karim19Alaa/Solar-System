
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <Planet.h>

Planet::Planet(float radius, float orbitRadius, float spinVelocity,
                 float orbitVelocity, float spinAngle, float orbitAngle, float color[3]){
    this->radius = radius;
    this->orbitRadius = orbitRadius;
    this->spinVelocity = spinVelocity;
    this->orbitVelocity = orbitVelocity;
    this->spinAngle = spinAngle;
    this->orbitAngle = orbitAngle;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];

    //TODO: set lightAmbient, lightDiffuse, lightPosition


}

void Planet::draw(){
    glPushMatrix();
        glRotatef(orbitAngle, 0, 0, 1);
        glTranslatef(0, 0, orbitRadius);
        glRotatef(spinAngle, 0, 0, 1);
        //TODO: light
        glutWireSphere(radius, 10, 10);
        glPopMatrix();
}

void Planet::update(){
    spinAngle += spinVelocity;
    if(spinAngle >= 360)    spinAngle -= 360;

    orbitAngle += orbitVelocity;
    if(orbitAngle >= 360)   orbitAngle -= 360;  
}