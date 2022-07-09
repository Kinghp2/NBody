//
// Created by Salvatore Marchese on 27/06/22.
//

#ifndef CLION_MODERN_OPENGL_VECTOR_H
#define CLION_MODERN_OPENGL_VECTOR_H
#include <cmath>
#include <vector>
#include <assert.h>
#include <iostream>

using namespace std;

struct Vector {

    double x, y, z;
    double magnitude;

    Vector(double _x, double _y, double _z) {
        x = double(_x);
        y = double(_y);
        z = double(_z);
        magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }


    Vector() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
        magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }

    static Vector zeros() {
        Vector zeros{ 0, 0, 0 };
        return zeros;
    }

    static Vector random() {
        Vector random{ double(rand() - RAND_MAX / 2), double(rand() - RAND_MAX / 2), double(rand() - RAND_MAX / 2) };
        return random;
    }


    Vector operator+ (Vector b) const {
        Vector* c = new Vector;
        c->x = x + b.x;
        c->y = y + b.y;
        c->z = z + b.z;
        return *c;
    }

    void operator+= (Vector b) {
        x += b.x;
        y += b.y;
        z += b.z;
    }

    Vector operator- (Vector& b) const {
        Vector c;
        c.x = double(x - b.x);
        c.y = double(y - b.y);
        c.z = double(z - b.z);
        c.setMagnitude();

        return c;
    }

    void setMagnitude() {
        this->magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }

    double calculate_magnitude() {
        return double(sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2)));

    }
    double operator* (Vector b) const {
        double c = 0.0;
        c += x * b.x;
        c += y * b.y;
        c += z * b.z;
        return c;
    }

    Vector operator* (double& b) const {
        Vector c;
        c.x = x * b;
        c.y = y * b;
        c.z = z * b;
        return c;
    }

    void log() const {
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }

    string to_string() {
        string to_return = ::to_string(x) + ::to_string(y) + ::to_string(z);
        return to_return;
    }

    string to_json() {
        string to_return =::to_string(x) + "," + ::to_string(y) + "," + ::to_string(z);
        return to_return;
    }

};



#endif //CLION_MODERN_OPENGL_VECTOR_H
