#include <iostream>
#include <vector>
#include "../Body.h"

class Store
{

public:
    Store(vector<Body> &bodies) : mBodies(bodies){};
    void store();
    void store_mass();

private:
    vector<Body> &mBodies;
};