#include <iostream>
#include <queue>
#include <random>

using namespace std;

#define LOOP_NUM 100000000
#define SAMPLE_NUM 100000
#define randint(min, max) (rand() % (max - min + 1) + min)

int main() {
    priority_queue<float, std::vector<float>, std::greater<float>> q1; // 最小堆  95
    priority_queue<float, std::vector<float>, std::greater<float>> q2; // 最小堆  99
    std::normal_distribution<float> n(0, 1); //均值, 方差
    std::default_random_engine e; //引擎

    std::vector<float> v;
    for (long i = 0; i < LOOP_NUM; i++) {
        if (i < SAMPLE_NUM) {
            v.push_back(n(e));
        } else {
            long r = randint(0, i);
            float ne = n(e);
            if (r < SAMPLE_NUM) {
                v[r] = ne;
            }
        }
    }
    int q1_cap = (int) (SAMPLE_NUM * 0.05);
    int q2_cap = (int) (SAMPLE_NUM * 0.01);
    for (int i = 0; i < SAMPLE_NUM; i++) {
        if (i < q1_cap) {
            q1.push(v[i]);
        } else {
            if (v[i] > q1.top()) {
                q1.push(v[i]);
                q1.pop();
            }
        }
        if (i < q2_cap) {
            q2.push(v[i]);
        } else {
            if (v[i] > q2.top()) {
                q2.push(v[i]);
                q2.pop();
            }
        }
    }
    std::cout << q1.top() << std::endl;
    std::cout << q2.top() << std::endl;
    return 0;
}