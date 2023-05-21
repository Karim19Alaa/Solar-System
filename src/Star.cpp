
#include <Star.h>
#include<iostream>

Star::Star(GLenum lightID, float radius, float spinVelocity, float spinAngle, float color[3]){
    this->lightID = lightID;
    this->radius = radius;
    this->spinVelocity = spinVelocity;
    this->spinAngle = spinAngle;
    // this->color[0] = color[0];
    // this->color[1] = color[1];
    // this->color[2] = color[2];

    //TODO: set lightAmbient, lightDiffuse, lightPosition


    // this->lightAmbient[0] = 0;
    // this->lightAmbient[1] = 0;
    // this->lightAmbient[2] = 0;
    this->lightAmbient[0] = color[0];
    this->lightAmbient[1] = color[1];
    this->lightAmbient[2] = color[2];
    this->lightAmbient[3] = 1;


    this->lightDiffuse[0] = 0;
    this->lightDiffuse[1] = 0;
    this->lightDiffuse[2] = 0;
    this->lightDiffuse[3] = 0;


    this->lightPosition[0] = 0;
    this->lightPosition[1] = 0;
    this->lightPosition[2] = 0;
    this->lightPosition[3] = 1;


}

// void multiply(float m[4][4], float v[4] , float u[4]){
//     for(int i = 0; i < 4; i++){
//         u[i] = 0;
//         for(int j = 0; j < 4; j++){
//             u[i] += m[j][i] * v[j];
//         }
//     }
// }

void Star::draw(){
    glEnable(lightID);

    glLightfv(lightID, GL_DIFFUSE, lightAmbient);
    float w[] = {0.1, 0.1, 0.1, 1};

    glLightfv(lightID, GL_SPECULAR, w);
    glLightfv(lightID, GL_POSITION, lightPosition);



    // glLightf(lightID, GL_LINEAR_ATTENUATION, 0.0001f);
    // glLightf(lightID, GL_QUADRATIC_ATTENUATION, 0.0001f);
    
    // glPushMatrix();
        // glLoadIdentity();
        // glLightfv(lightID, GL_POSITION, lightPosition);
        // float red[] = {1, 0, 0, 0};
        // glMaterialfv(GL_FRONT, GL_AMBIENT, red);
        // glutSolidCone(10, 20, 20, 20);
    // glPopMatrix();

    glMaterialfv(GL_FRONT, GL_EMISSION, lightAmbient);

    glPushMatrix();
        glRotatef(spinAngle, 0, 1, 0);
        glRotatef(90, 1, 0, 0);

        glutSolidSphere(radius, 20, 20);
    glPopMatrix();

    glMaterialfv(GL_FRONT, GL_EMISSION, lightDiffuse);

}

void Star::update(){
    spinAngle += spinVelocity;
    if(spinAngle >= 360)    spinAngle -= 360;
}