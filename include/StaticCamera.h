#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>

#include <Director.h>

class StaticCamera: public Director{

private:
    double eye[3], center[3], up[3];

public:
    StaticCamera(double eye[3], double center[3], double up[3]);
    void pointCamera() override;
    ~StaticCamera();
};