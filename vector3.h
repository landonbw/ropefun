#ifndef VECTOR3_H
#define VECTOR3_H

#include <string>
#include <QString>


class Vector3
{
public:
    Vector3();
    Vector3(double x, double y, double z);
    // return the x, y, z values of the vector
    void get_xyz(double &x, double &y, double &z) const;
    // set the x, y, z values of the vector
    void set_xyz(double x, double y, double z);
    // itemwise addition of the vector and vec
    Vector3 add(const Vector3 &vec) const;
    // add val to each value in the vector
    Vector3 add(const double &val) const;
    // itemwise subtraction of vec from the vector
    Vector3 subtract(const Vector3 &vec) const;
    // subtract val from each value in the vector
    Vector3 subtract(const double &val) const;
    // multipy each value in the vector by val
    Vector3 multiply(const double &val) const;
    // divide each value in the vector by divisor
    Vector3 divide(const double &divisor) const;
    // print the vector to the console
    void print();
    // return the vector string
    QString get_info();
    // find the length of the vector
    double length() const;
    // normalize the vector
    void normalize();
    // Itemwise addition of v1 and v2
    static Vector3 add(const Vector3 v1, const Vector3 v2);
    // itemwise subtraction of v1 and v2
    static Vector3 subtract(const Vector3 v1, const Vector3 v2);
    // unary to negate the vector values
    Vector3 operator-();
    // operator to increment and add value
    Vector3& operator+=(const Vector3 v2);


private:
    double mX{0};
    double mY{0};
    double mZ{0};
};

Vector3 operator+(const Vector3 &v1, const Vector3 &v2);
Vector3 operator+(const Vector3 &v1, const double &val);
Vector3 operator-(const Vector3 &v1, const Vector3 &v2);
Vector3 operator-(const Vector3 &v1, const double &val);
Vector3 operator*(const Vector3 &v1, const double &val);
Vector3 operator*(const double &val, const Vector3 &v1);
Vector3 operator/(const Vector3 &v1, const double &val);

#endif // VECTOR3_H
