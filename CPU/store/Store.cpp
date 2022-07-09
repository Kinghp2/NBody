#include "Store.h"
#include <string>
#include <fstream>
#include <experimental/filesystem>

using namespace std;

void Store::store()
{
    int i = 0;
    filesystem::create_directory("./data");
    for (auto b = mBodies.begin(); b != mBodies.end(); *b++, i++)
    {
        auto fileName = "./data/" + to_string(i) + ".csv";
        ofstream file(fileName, std::ios::out | std::ios::app);
        file << b->r.to_json() << endl;
        file.close();
    }
}

void Store::store_mass()
{
    int i = 0;
    filesystem::create_directory("./data");
    for (auto b = mBodies.begin(); b != mBodies.end(); *b++, i++)
    {
        auto fileName = "./data/" + to_string(i) + ".csv";
        ofstream file(fileName, std::ios_base::app);
        file << b->mass << ", "
             << double(0.0) << ", " << double(0.0) << endl;
        file.close();
    }
}