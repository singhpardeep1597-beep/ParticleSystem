#include <vector>
#include "Particl.h"

using namespace std;

class ParticleSystem
{
public:

#define POOL_SIZE 1000 // Max 1000 particles
    // Object pooling

    vector<Particl> pool;


    void Main(); // the Raylib stuff
    void Start(); // where starting stuff goes
    void Update(); // frame by frame calculation

};
