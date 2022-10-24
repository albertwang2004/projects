#include <random>
using namespace std;
class Random {
    static std::mt19937 rand;
public:
    static int Int(int m, int M);
};
