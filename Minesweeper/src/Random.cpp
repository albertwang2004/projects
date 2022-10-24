#include "Random.h"
#include <ctime>
using namespace std;
std::mt19937 Random::rand(time(0));
int Random::Int(int m, int M) {
    std::uniform_int_distribution<int> dist(m,M);
    return dist(rand);
}
