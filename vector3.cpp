#include "vector3.h"
#include <iostream>
#include <cmath>

Vector3::Vector3()
{

}

Vector3::Vector3(double x, double y, double z)
{
    mX = x;
    mY = y;
    mZ = z;
}

void Vector3::get_xyz(double &x, double &y, double &z) const
{
    x = this->mX;
    y = this->mY;
    z = this->mZ;
}

void Vector3::set_xyz(double x, double y, double z)
{
    this->mX = x;
    this->mY = y;
    this->mZ = z;
}

Vector3 Vector3::add(const double &val) const
{
    Vector3 newVec = Vector3(this->mX + val, this->mY + val, this->mZ + val);
    return newVec;
}

Vector3 Vector3::add(const Vector3 &vec) const
{
    Vector3 newVec = Vector3(this->mX + vec.mX, this->mY + vec.mY, this->mZ + vec.mZ);
    return newVec;
}

Vector3 Vector3::subtract(const double &val) const
{
    Vector3 newVec = Vector3(this->mX - val, this->mY - val, this->mZ - val);
    return newVec;
}

Vector3 Vector3::subtract(const Vector3 &vec) const
{
    Vector3 newVec = Vector3(this->mX - vec.mX, this->mY - vec.mY, this->mZ - vec.mZ);
    return newVec;
}

Vector3 Vector3::multiply(const double &val) const
{
    Vector3 newVec = Vector3(this->mX * val, this->mY * val, this->mZ * val);
    return newVec;
}

Vector3 Vector3::divide(const double &divisor) const
{
    Vector3 newVec = Vector3(this->mX / divisor, this->mY / divisor, this->mZ / divisor);
    return newVec;
}

void Vector3::print()
{
    std::cout << "x: " << this->mX << "\ty: " << this->mY << "\tz: " << this->mZ << std::endl;
}

QString Vector3::get_info()
{
    QString str = QString("(%1, %2, %3)").arg(mX).arg(mY).arg(mZ);
    return str;
}

double Vector3::length() const
{
    double len = sqrt(mX * mX + mY * mY + mZ * mZ);
    return len;
}

void Vector3::normalize()
{
    double length = this->length();
    this->mX /= length;
    this->mY /= length;
    this->mZ /= length;
}

Vector3 Vector3::add(const Vector3 v1, const Vector3 v2)
{
    Vector3 newVec = Vector3(v1.mX + v2.mX, v1.mY + v2.mY, v1.mZ + v2.mZ);
    return newVec;
}

Vector3 Vector3::subtract(const Vector3 v1, const Vector3 v2)
{
    Vector3 newVec = Vector3(v1.mX - v2.mX, v1.mY - v2.mY, v1.mZ - v2.mZ);
    return newVec;
}

Vector3 Vector3::operator-()
{
    Vector3 newVec;
    newVec.mX = (this->mX) * -1;
    newVec.mY = (this->mY) * -1;
    newVec.mZ = (this->mZ) * -1;
    return newVec;
}

Vector3 &Vector3::operator+=(const Vector3 v2)
{
    this->mX += v2.mX;
    this->mY += v2.mY;
    this->mZ += v2.mZ;
    return *this;
}







Vector3 operator+(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3::add(v1, v2);
}

Vector3 operator+(const Vector3 &v1, const double &val)
{
    return v1.add(val);
}

Vector3 operator-(const Vector3 &v1, const Vector3 &v2)
{
    return Vector3::subtract(v1, v2);
}

Vector3 operator-(const Vector3 &v1, const double &val)
{
    return v1.subtract(val);
}

Vector3 operator*(const Vector3 &v1, const double &val)
{
    double x{0}, y{0}, z{0};
    v1.get_xyz(x, y, z);
    Vector3 newVec = Vector3(x*val, y*val, z*val);
    return newVec;
}


Vector3 operator/(const Vector3 &v1, const double &val)
{
    return v1.divide(val);
}

Vector3 operator*(const double &val, const Vector3 &v1)
{
    double x{0}, y{0}, z{0};
    v1.get_xyz(x, y, z);
    Vector3 newVec = Vector3(x*val, y*val, z*val);
    return newVec;
}
