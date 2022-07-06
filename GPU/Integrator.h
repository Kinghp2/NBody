//
// Created by Salvatore Marchese on 27/06/22.
//

#ifndef CLION_MODERN_OPENGL_INTEGRATOR_H
#define CLION_MODERN_OPENGL_INTEGRATOR_H

#include <iostream>
#include <utility>
#include <vector>
#include "Body.h"
#include "numcpp/matrix.h"
#include <map>
#include "./store/Store.h"

class Integrator
{
public:
    Integrator(vector<Body>& bodies, double time_step, double T) :
            m_bodies(bodies),
            m_time_step(time_step),
            T(T)
    {};
    std::vector<Body>& m_bodies;
    double m_time_step;
    double G_const = 6.67408e-11;
    double T;
    Store storer{m_bodies};
};

class Euler : public virtual Integrator
{
public:
    using Integrator::Integrator;
    void update_locations();
    matrix compute_positions(double T);
    void simulate();

private:
    Vector calculate_g(std::vector<Body>::iterator, Body*);
    Vector calculate_single_body_acceleration(int& index, Body& target_body);
    std::map<vector<int>, Vector> repeated_pairs;
    bool pair_is_stored(int&, int&);
    void store_pair(int&, int&, Vector&);
    Vector get_pair(int&, int&);
};


#endif //CLION_MODERN_OPENGL_INTEGRATOR_H
