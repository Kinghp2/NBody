#include "Integrator.h"
#include "Body.h"
using namespace std;

#define N 10

#define print(x) std::cout << x << std::endl;

vector<Body> generate_bodies() {
    vector<Body> bodies;
    for (int i = 0; i < N; i++) {
        Body b = Body::from_random();
        bodies.push_back(b);
    }
    return bodies;
}

int main(int argc, char** argv)
{
    double time_step = 1e-1;
    double T = 1e2;
    vector<Body> bodies = generate_bodies();
    Euler* integrator = new Euler{bodies, time_step, T};

    integrator->simulate();
    delete integrator;
    return 0;

}

