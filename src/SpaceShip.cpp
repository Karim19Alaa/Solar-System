#include <SpaceShip.h>

SpaceShip::SpaceShip(float x, float z, float angle){
    this->x = x;
    this->z = z;
    this->angle = angle;
}
SpaceShip::~SpaceShip(){}

void SpaceShip::draw(){
    float color[] = {0, 1, 1, 1};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glPushMatrix();
        glTranslatef(x, 0, z);
        glRotatef(angle, 0, 1, 0);
        glutSolidTeapot(6);
    glPopMatrix();
}

void SpaceShip::update(){
    //pass
}

void SpaceShip::pointCamera(){
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-20.0, 20.0, -20.0, 20.0, 5.0, 600.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
    gluLookAt(x + 9 * cos(angle * M_PI / 180.0), 0, z - 9 * sin(angle * M_PI / 180.0),
                x + 10 * cos(angle * M_PI / 180.0), 0, z - 10 * sin(angle * M_PI / 180.0),
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