#include "Store.h"
#include <string>
#include <fstream>
using namespace std;

void Store::store() {
    int i = 0;
    for (auto b = mBodies.begin(); b != mBodies.end(); *b++, i++) {
        auto fileName = "./data/"+to_string(i)+".dat";
        ofstream file(fileName, std::ios_base::app);
        file << b->r.to_json() << endl;
        file.close();
    }
}