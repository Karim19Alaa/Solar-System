#include <SpaceShip.h>

SpaceShip::SpaceShip(float x, float z, float angle){
    this->x = x;
    this->z = z;
    this->angle = angle;
}
SpaceShip::~SpaceShip(){}

void SpaceShip::draw(){
    glColor3f(0, 1, 1);
    glPushMatrix();
        glTranslatef(x, 0, z);
        glRotatef(angle, 0, 1, 0);
        glutWireTeapot(10);
    glPopMatrix();
}

void SpaceShip::update(){
    //TODO
}

void SpaceShip::pointCamera(){
	glLoadIdentity();
    gluLookAt(x + 13 * cos(angle * M_PI / 180.0), 0, z - 13 * sin(angle * M_PI / 180.0),
                x + 14 * cos(angle * M_PI / 180.0), 0, z - 14 * sin(angle * M_PI / 180.0),
                0, 1, 0);

}

void SpaceShip::throttle(){
    x +=  cos(angle * M_PI / 180.0);
    z -=  sin(angle * M_PI / 180.0);
}

void SpaceShip::reverse(){
    x -=  cos(angle * M_PI / 180.0);
    z +=  sin(angle * M_PI / 180.0);
}

void SpaceShip::steerLeft(){
    angle += 5.0;
    if(angle >= 360)    angle -= 360;
}
void SpaceShip::steerRight(){
    angle -= 5.0;
    if(angle <= 0)    angle += 360;
}