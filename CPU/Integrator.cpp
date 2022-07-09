//
// Created by Salvatore Marchese on 27/06/22.
//

#include "Integrator.h"
#include "Body.h"
#include <chrono>
#include <iostream>
#include <time.h>

uint64_t Integrator::timer()
{
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    return (uint64_t)start.tv_nsec + (uint64_t)start.tv_sec * 1000000000;
}

static std::mutex _sMutex;

void Euler::calculate_single_body_acceleration(int &index,
                                                 Body &target_body)
{
    // It just applies Newton's second law.
    int i = 0;
    // You're doing practically (19)*(N-1) additions
    for (auto ex_b = m_bodies.begin(); ex_b != m_bodies.end(); *ex_b++, i++)
    {
        if (i != index && i > index)
        {
            double G_const = 6.67408e-11;
            Vector r_diff = ex_b->r - (target_body.r);
            double acc = G_const * ex_b->mass /
                         pow(r_diff.magnitude, 3);
            Vector da = r_diff * acc;
            target_body.acceleration += da;
            ex_b->acceleration += da;
        }
    }
}

void Euler::update_locations()
{
    // 19*N*(N-1)
    int i = 0;
    std::lock_guard<std::mutex> lock(_sMutex);
    for (auto b = m_bodies.begin(); b != m_bodies.end(); *b++, i++)
    {
        calculate_single_body_acceleration(i, (*b));
        b->velocity += b->acceleration * m_time_step;
        b->r += b->velocity * m_time_step;
    }
}

void Euler::simulate()
{
    int N = int(T / m_time_step);
    // storer.store_mass();
    for (int i = 0; i < N; i++)
    {
        uint64_t start = timer();
        update_locations();
        uint64_t stop = timer();
        auto time = (stop - start) * 1e-9;

        int A = m_bodies.size();
        auto gflops = 25 * A * A * 1e-9;
        cout << "GFLOPS: " << gflops / time << endl;
        // storer.store();
    }
}

matrix Euler::compute_positions(double T)
{
    int N = int(T / m_time_step);
    matrix M(3, int(m_bodies.size()));
    for (int i = 0; i < N; i++)
    {
        update_locations();
    }
    return M;
}

Vector Euler::calculate_g(std::vector<Body>::iterator body, Body *tbody)
{
    Vector r_diff = body->r - (tbody->r);
    double acc = G_const * body->mass /
                 pow(r_diff.magnitude, 3);
    return r_diff * acc;
}
