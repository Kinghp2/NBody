//
// Created by Salvatore Marchese on 27/06/22.
//

#ifndef CLION_MODERN_OPENGL_BODY_H
#define CLION_MODERN_OPENGL_BODY_H

#include "numcpp/vector.h"
#include <random>
#include <cstdlib>
#include <iostream>

using namespace std;


struct Body {
    double mass;
    Vector r;
    Vector velocity;
    Vector acceleration;


    static float generate_random() {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<float> dist(1.0, 1e4);
        return (float)dist(mt);
    }

    static Body from_random() {
        Vector r = Vector::random();
        Vector v = Vector::random();
        double mass = double(rand());
        Vector a = Vector::zeros();
        Body b(mass, r, v, a);
        return b;
    }

    Body(double m_mass, Vector m_r, Vector m_velocity, Vector m_acceleration) :
        mass(m_mass), r(m_r), velocity(m_velocity), acceleration(m_acceleration) {
    };
};



#endif //CLION_MODERN_OPENGL_BODY_H
