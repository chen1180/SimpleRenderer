#pragma once

#include <vector>
#include <memory>
#include "Vector.hpp"
#include"Object.h"
#include "Light.h"
#include"Arcball.h"
class Scene
{
public:
    Scene() {}
    // setting up options
    int width = 800;
    int height = 600;
    double fov = 60;
    Vector3f backgroundColor = Vector3f(0.235294, 0.67451, 0.843137);
    int maxDepth = 5;
    float epsilon = 0.00001;

    QVector2D prev_mouse=QVector2D(-0.f,-0.f);
public:
    // timing
    float deltaTime = 0.0f;	// time between current frame and last frame
    float lastFrame = 0.0f;
    int frameCount = 0;
    Arcball arcball = Arcball(QVector3D(13.0, 2.0, 3.0), QVector3D(0.0, 0.0, 0.0), QVector3D(0.0, 1.0, 0.0));
    Scene(int w, int h) : width(w), height(h){}

    void Render(QOpenGLFunctions_4_3_Core* f);
    void Add(std::unique_ptr<Object> object) { objects.push_back(std::move(object)); }
    void Add(std::unique_ptr<Light> light) { lights.push_back(std::move(light)); }

    [[nodiscard]] const std::vector<std::unique_ptr<Object> >& get_objects() const { return objects; }
    [[nodiscard]] const std::vector<std::unique_ptr<Light> >& get_lights() const { return lights; }


private:
    // creating the scene (adding objects and lights)
    std::vector<std::unique_ptr<Object> > objects;
    std::vector<std::unique_ptr<Light> > lights;
};