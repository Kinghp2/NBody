//
// Created by Salvatore Marchese on 27/06/22.
//

#include "Integrator.h"
#include "Body.h"
#include <chrono>
#include <iostream>

using namespace std;

Vector Euler::calculate_single_body_acceleration(int& index,
                                                 Body& target_body) {
    // It just applies Newton's second law.
    int i = 0;
    Vector acceleration{0.0, 0.0, 0.0};
    // You're doing practically (19)*(N-1) additions
    for (auto ex_b = m_bodies.begin(); ex_b != m_bodies.end(); *ex_b++, i++) {
        if (i != index) {
            if (pair_is_stored(i, index)) {
                acceleration += get_pair(i, index);
            }else {
                Vector da = calculate_g(ex_b, &target_body);
                acceleration += da;
                store_pair(i, index, da);
            }
        }
    }
    return acceleration;
}

void Euler::simulate() {
    int N = int(T/m_time_step);
    for (int i = 0; i < N; i++) {
        update_locations();
    }

}
void Euler::update_locations() {
    // 19*N*(N-1)
    auto start =
            std::chrono::high_resolution_clock::now();
    repeated_pairs.clear();
    int i = 0;
    for (auto b = m_bodies.begin(); b != m_bodies.end(); *b++, i++) {
        b->velocity += calculate_single_body_acceleration(i, *b)
                * m_time_step;
        b->r += b->velocity*m_time_step;
    }
    auto stop =std::chrono::high_resolution_clock::now();
    auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>
                    (stop - start);
    auto time = duration.count()*1e-6;
    int N = m_bodies.size();
    auto gflops = (N*N / time)*1e-9;
    cout << "GFLOPS: " << gflops << endl;
    storer.store();
}


bool Euler::pair_is_stored(int& i, int& j) {
    if (repeated_pairs.size() > 0) {
        vector<int> arr1 = {i, j};
        vector<int> arr2 = {j, i};
        if (repeated_pairs.find(arr1) != repeated_pairs.end() && repeated_pairs.find(arr2) != repeated_pairs.end()) {
            return true;
        }
    }
    return false;
}

Vector Euler::get_pair(int& i, int& j)  {
    /*
     * Returns the (i, j) force pair
     */
    if (repeated_pairs.find({i, j}) != repeated_pairs.end()) {
        return repeated_pairs[{i, j}];
    }else {
        return repeated_pairs[{j, i}];
    }
}

void Euler::store_pair(int& i, int& j, Vector& acceleration_ij) {
    repeated_pairs[{i, j}] = acceleration_ij;
}

matrix Euler::compute_positions(double T) {
    int N = int(T/m_time_step);
    matrix M(3, int(m_bodies.size()));
    for (int i = 0; i < N; i++) {
        update_locations();
    }
    return M;
}

Vector Euler::calculate_g(std::vector<Body>::iterator body, Body* tbody) {
    Vector r_diff = body-> r - (tbody->r);
    double acc =  G_const * body->mass /
                  pow(r_diff.magnitude, 3);
    return r_diff* acc;
}
