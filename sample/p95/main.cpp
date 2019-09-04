#include <iostream>
#include <queue>
#include <random>

using namespace std;

#define LOOP_NUM 100000000
#define SAMPLE_NUM 100000
#define randint(min, max) (rand() % (max - min + 1) + min)

int main() {
    priority_queue<float, std::vector<float>, std::greater<float>> q1; // 最小堆  95
    std::normal_distribution<float> n(0, 1); //均值, 方差
    std::default_random_engine e; //引擎

    std::vector<float> v;
    for (long i = 0; i < LOOP_NUM; i++) {
        float ne = n(e);
        if (i < SAMPLE_NUM) {
            v.push_back(ne);
        } else {
            long r = randint(0, i);
            if (r < SAMPLE_NUM) {
                v[r] = ne;
            }
        }
    }
    int q1_cap = (int) (SAMPLE_NUM * 0.05);
    for (int i = 0; i < SAMPLE_NUM; i++) {
        if (i < q1_cap) {
            q1.push(v[i]);
        } else {
            if (v[i] > q1.top()) {
                q1.push(v[i]);
                q1.pop();
            }
        }
    }
    std::cout << q1.top() << std::endl;
    return 0;
}