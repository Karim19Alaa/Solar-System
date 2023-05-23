
#include <Star.h>
#include<iostream>

Star::Star(GLenum lightID, float radius, float spinVelocity, float axisAngle, float color[3]){
    this->lightID = lightID;
    this->radius = radius;
    this->spinVelocity = spinVelocity;
    this->spinAngle = spinAngle;

    this->light_Ambient_Diffuse[0] = color[0];
    this->light_Ambient_Diffuse[1] = color[1];
    this->light_Ambient_Diffuse[2] = color[2];
    this->light_Ambient_Diffuse[3] = 1;


}

void Star::draw()
{
    glEnable(lightID);

    glLightfv(lightID, GL_AMBIENT_AND_DIFFUSE, light_Ambient_Diffuse);
    float w[] = {0.1, 0.1, 0.1, 1};

    glLightfv(lightID, GL_SPECULAR, w);

    float lightPosition[4] = {0, 0, 0, 1};
    glLightfv(lightID, GL_POSITION, lightPosition);



    glLightf(lightID, GL_LINEAR_ATTENUATION, 0.0001f);
    glLightf(lightID, GL_QUADRATIC_ATTENUATION, 0.0001f);
    

    glMaterialfv(GL_FRONT, GL_EMISSION, light_Ambient_Diffuse);

    glPushMatrix();
        glRotatef(spinAngle, 0, 1, 0);
        glRotatef(90, 1, 0, 0);

        glutSolidSphere(radius, 40, 40);
    glPopMatrix();

    float reset[4] = {0};
    glMaterialfv(GL_FRONT, GL_EMISSION, reset);
}

void Star::update(){
    spinAngle += spinVelocity;
    if(spinAngle >= 360)    spinAngle -= 360;
}