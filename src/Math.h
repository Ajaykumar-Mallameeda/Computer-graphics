#pragma once

#include <cmath>

struct Mat4
{
    float m[16];

    static Mat4 identity();

    static Mat4 translation(
        float x,
        float y,
        float z
    );

    static Mat4 rotationX(
        float degrees
    );

    static Mat4 rotationY(
        float degrees
    );

    static Mat4 perspective(
        float fovDegrees,
        float aspect,
        float nearPlane,
        float farPlane
    );

    static Mat4 lookAt(
        float eyeX, float eyeY, float eyeZ,
        float centerX, float centerY, float centerZ,
        float upX, float upY, float upZ
    );

    Mat4 operator*(const Mat4& other) const;
};