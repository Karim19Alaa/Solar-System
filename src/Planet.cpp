

#include <Planet.h>

Planet::Planet(float radius, float orbitRadius, float spinVelocity,
                 float orbitVelocity, float spinAngle, float orbitAngle, float color[3]){
    this->radius = radius;
    this->orbitRadius = orbitRadius;
    this->spinVelocity = spinVelocity;
    this->orbitVelocity = orbitVelocity;
    this->spinAngle = spinAngle;
    this->orbitAngle = orbitAngle;



    this->light_Ambient_Diffuse[0] = color[0];
    this->light_Ambient_Diffuse[1] = color[1];
    this->light_Ambient_Diffuse[2] = color[2];
    this->light_Ambient_Diffuse[3] = 1;


}

void Planet::draw(){
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, light_Ambient_Diffuse);
    float w[] = {0.1, 0.1, 0.1, 1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, w);

    glPushMatrix();
        glRotatef(orbitAngle, 0, 1, 0);
        glTranslatef(orbitRadius, 0, 0);
        glRotatef(spinAngle, 0, 1, 0);
        glRotatef(90, 1, 0, 0);
        glutSolidSphere(radius, 40, 40);
    glPopMatrix();

    float reset[4] = {0};

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, reset);

}

void Planet::update(){
    spinAngle += spinVelocity;
    if(spinAngle >= 360)    spinAngle -= 360;

    orbitAngle += orbitVelocity;
    if(orbitAngle >= 360)   orbitAngle -= 360;  
}