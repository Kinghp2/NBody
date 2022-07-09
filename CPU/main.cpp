#include "Integrator.h"
#include "Body.h"
using namespace std;

#define N 10

#define print(x) std::cout << x << std::endl;

vector<Body> generate_bodies()
{
    vector<Body> bodies __attribute__((aligned(64)));
    for (int i = 0; i < N; i++)
    {
        Body b = Body::from_random();
        bodies.push_back(b);
    }
    return bodies;
}

int main(int argc, char **argv)
{
    double time_step = 1e-3;
    double T = 100;
    vector<Body> bodies = generate_bodies();
    Euler *integrator = new Euler{bodies, time_step, T};

    integrator->simulate_async();
    delete integrator;
    return 0;
}
