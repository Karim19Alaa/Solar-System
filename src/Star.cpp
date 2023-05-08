
#include <Star.h>

Star::Star(float radius, float spinVelocity, float spinAngle, float color[3]){
    this->radius = radius;
    this->spinVelocity = spinVelocity;
    this->spinAngle = spinAngle;
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];

    //TODO: set lightAmbient, lightDiffuse, lightPosition
}

void Star::draw(){
    glPushMatrix();
        glRotatef(spinAngle, 0, 1, 0);
        glColor3f(color[0], color[1], color[2]);
        glRotatef(90, 1, 0, 0);
        glutWireSphere(radius, 20, 20);
    glPopMatrix();
}

void Star::update(){
    spinAngle += spinVelocity;
    if(spinAngle >= 360)    spinAngle -= 360;
}