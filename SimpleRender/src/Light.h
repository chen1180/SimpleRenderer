#pragma once
#include<qvector3d.h>
#include"MeshTriangle.h"
#include<qstring.h>
class Light
{
public:
    Light(const QVector3D& p, const float& i)
        : position(p)
        , intensity(i)
    {}

    virtual ~Light() = default;

    QVector3D position;
    QVector3D ambient;
    QVector3D diffuse;
    QVector3D specular;
    float intensity;
    MeshTriangle* shape;
};


