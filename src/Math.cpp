#include "Math.h"

#include <cmath>

Mat4 Mat4::rotationX(float degrees)
{
    Mat4 result = Mat4::identity();

    float radians =
        degrees * 3.14159265359f / 180.0f;

    float c = std::cos(radians);
    float s = std::sin(radians);

    result.m[5] = c;
    result.m[6] = s;

    result.m[9] = -s;
    result.m[10] = c;

    return result;
}


Mat4 Mat4::rotationY(float degrees)
{
    Mat4 result = Mat4::identity();

    float radians =
        degrees * 3.14159265359f / 180.0f;

    float c = std::cos(radians);
    float s = std::sin(radians);

    result.m[0] = c;
    result.m[2] = -s;

    result.m[8] = s;
    result.m[10] = c;

    return result;
}

Mat4 Mat4::identity()
{
    Mat4 result{};

    result.m[0]  = 1.0f;
    result.m[5]  = 1.0f;
    result.m[10] = 1.0f;
    result.m[15] = 1.0f;

    return result;
}

Mat4 Mat4::translation(
    float x,
    float y,
    float z)
{
    Mat4 result = Mat4::identity();

    result.m[12] = x;
    result.m[13] = y;
    result.m[14] = z;

    return result;
}

Mat4 Mat4::perspective(
    float fovDegrees,
    float aspect,
    float nearPlane,
    float farPlane)
{
    Mat4 result{};

    const float pi = 3.14159265359f;

    const float fovRadians =
        fovDegrees * pi / 180.0f;

    const float tanHalfFov =
        std::tan(fovRadians / 2.0f);

    result.m[0] =
        1.0f / (aspect * tanHalfFov);

    result.m[5] =
        1.0f / tanHalfFov;

    result.m[10] =
        -(farPlane + nearPlane) /
        (farPlane - nearPlane);

    result.m[11] = -1.0f;

    result.m[14] =
        -(2.0f * farPlane * nearPlane) /
        (farPlane - nearPlane);

    return result;
}


Mat4 Mat4::lookAt(
    float eyeX, float eyeY, float eyeZ,
    float centerX, float centerY, float centerZ,
    float upX, float upY, float upZ)
{
    // Forward direction
    float fx = centerX - eyeX;
    float fy = centerY - eyeY;
    float fz = centerZ - eyeZ;

    float fLength =
        std::sqrt(
            fx * fx +
            fy * fy +
            fz * fz
        );

    fx /= fLength;
    fy /= fLength;
    fz /= fLength;


    // Normalize up vector
    float upLength =
        std::sqrt(
            upX * upX +
            upY * upY +
            upZ * upZ
        );

    upX /= upLength;
    upY /= upLength;
    upZ /= upLength;


    // Side = Forward × Up
    float sx =
        fy * upZ -
        fz * upY;

    float sy =
        fz * upX -
        fx * upZ;

    float sz =
        fx * upY -
        fy * upX;

    float sLength =
        std::sqrt(
            sx * sx +
            sy * sy +
            sz * sz
        );

    sx /= sLength;
    sy /= sLength;
    sz /= sLength;


    // True up = Side × Forward
    float ux =
        sy * fz -
        sz * fy;

    float uy =
        sz * fx -
        sx * fz;

    float uz =
        sx * fy -
        sy * fx;


    Mat4 result{};

    result.m[0] = sx;
    result.m[1] = ux;
    result.m[2] = -fx;

    result.m[4] = sy;
    result.m[5] = uy;
    result.m[6] = -fy;

    result.m[8] = sz;
    result.m[9] = uz;
    result.m[10] = -fz;

    result.m[12] =
        -(sx * eyeX +
          sy * eyeY +
          sz * eyeZ);

    result.m[13] =
        -(ux * eyeX +
          uy * eyeY +
          uz * eyeZ);

    result.m[14] =
        fx * eyeX +
        fy * eyeY +
        fz * eyeZ;

    result.m[15] = 1.0f;

    return result;
}


Mat4 Mat4::operator*(const Mat4& other) const
{
    Mat4 result{};

    for (int column = 0; column < 4; ++column)
    {
        for (int row = 0; row < 4; ++row)
        {
            result.m[column * 4 + row] =
                m[0 * 4 + row] *
                    other.m[column * 4 + 0] +

                m[1 * 4 + row] *
                    other.m[column * 4 + 1] +

                m[2 * 4 + row] *
                    other.m[column * 4 + 2] +

                m[3 * 4 + row] *
                    other.m[column * 4 + 3];
        }
    }

    return result;
}