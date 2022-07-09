//
// Created by Salvatore Marchese on 27/06/22.
//

#ifndef CLION_MODERN_OPENGL_INTEGRATOR_H
#define CLION_MODERN_OPENGL_INTEGRATOR_H
#include <vector>
#include "../numcpp/Matrix.h"
#include "../storer/Store.h"

class BaseIntegrator
{
public:
    double m_time_step;
    double G_const = 6.67408e-11;
    double T;
    Storer storer;
    uint64_t timer();
};

#endif