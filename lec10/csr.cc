#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <numbers>
using namespace std;

constexpr float INF = numeric_limits<float>::infinity();

class csr{
private:
    vector<uint32_t> start_indices;
    vector<uint32_t> to;
    vector<float> w;

public:
    bool is_adjacent(int from, int dest){
        for (uint32_t i = start_indices[from]; i < start_indices[from+1]; i++){
            if(to[i] == dest)
                return w[i];
        }
        return INF;
    }





};