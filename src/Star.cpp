
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <Star.h>

Star::Star(float radius, float spinVelocity, float axisAngle, float color[3]){
    this->radius = radius;
    this->spinVelocity = spinVelocity;
    this->spinAngle = axisAngle;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];

    //TODO: set lightAmbient, lightDiffuse, lightPosition
}

void Star::draw(){
    glPushMatrix();
        glRotatef(spinAngle, 0, 0, 1);
        //TODO: light emiission
        glutWireSphere(radius, 10, 10);
        glPopMatrix();
}

void Star::update(){
    spinAngle += spinVelocity;
    if(spinAngle >= 360)    spinAngle -= 360;
}