#include <StaticCamera.h>

StaticCamera::StaticCamera(double eye[3], double center[3], double up[3]){
    this->eye[0] = eye[0];
    this->eye[1] = eye[1];
    this->eye[2] = eye[2];

    this->center[0] = center[0];
    this->center[1] = center[1];
    this->center[2] = center[2];

    this->up[0] = up[0];
    this->up[1] = up[1];
    this->up[2] = up[2];
}

void StaticCamera::pointCamera(){
	glLoadIdentity();
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 0);
    gluLookAt(eye[0], eye[1], eye[2],
                center[0], center[1], center[2],
                up[0], up[1], up[2]);
}

StaticCamera::~StaticCamera(){}