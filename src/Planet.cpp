

#include <Planet.h>

Planet::Planet(float radius, float orbitRadius, float spinVelocity,
                 float orbitVelocity, float spinAngle, float orbitAngle, float color[3]){
    this->radius = radius;
    this->orbitRadius = orbitRadius;
    this->spinVelocity = spinVelocity;
    this->orbitVelocity = orbitVelocity;
    this->spinAngle = spinAngle;
    this->orbitAngle = orbitAngle;
    // this->color[0] = color[0];
    // this->color[1] = color[1];
    // this->color[2] = color[2];

    //TODO: set lightAmbient, lightDiffuse

    this->lightAmbient[0] = color[0];
    this->lightAmbient[1] = color[1];
    this->lightAmbient[2] = color[2];
    this->lightAmbient[3] = 1;


    this->lightDiffuse[0] = 0;
    this->lightDiffuse[1] = 0;
    this->lightDiffuse[2] = 0;
    this->lightDiffuse[3] = 0;


    // this->lightPosition[0] = 0;
    // this->lightPosition[1] = 0;
    // this->lightPosition[2] = 0;
    // this->lightPosition[3] = 1;


}

void Planet::draw(){
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lightAmbient);
    float w[] = {0.1, 0.1, 0.1, 1};
    glMaterialfv(GL_FRONT, GL_SPECULAR, w);

    // glColor3f(color[0], color[1], color[2]);
    //TODO: light
    // glMaterialfv(GL_FRONT, GL_DIFFUSE, lightDiffuse);

    glPushMatrix();
        glRotatef(orbitAngle, 0, 1, 0);
        glTranslatef(orbitRadius, 0, 0);
        glRotatef(spinAngle, 0, 1, 0);
        glRotatef(90, 1, 0, 0);
        glutSolidSphere(radius, 20, 20);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, lightDiffuse);

}

void Planet::update(){
    spinAngle += spinVelocity;
    if(spinAngle >= 360)    spinAngle -= 360;

    orbitAngle += orbitVelocity;
    if(orbitAngle >= 360)   orbitAngle -= 360;  
}