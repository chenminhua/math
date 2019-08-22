/**
 * @ Author: Minhua Chen
 * @ Create Time: 2019-08-22 21:54:29
 * @ Modified by: Minhua Chen
 * @ Modified time: 2019-08-22 22:12:47
 * @ Description:
 */
#include <stdio.h>
#include <stdlib.h>

/*calculus pi by Monte Carlo method */
float pi1() {
    unsigned k = 0, n = 1e8;
    float i, j;
    for (int m = 0; m < n; m++) {
        i = (float)rand() / RAND_MAX;
        j = (float)rand() / RAND_MAX;
        if (i * i + j * j < 1.) k++;
    }

    return ((float)k/n )*4;
}

/*calculus pi by Leibniz series */
float pi2() {
    unsigned n = 1e8;
    float pi_qv = 1.0;
    int flag = -1;
    for (int i = 1; i < n; i++) {
        pi_qv += flag * (1./(2 * i + 1));
        flag = -flag;
    }
    return pi_qv * 4;
}

int main() {
    printf("calculus pi by Monte Carlo %f\n", pi1());
    printf("calculus pi by Leibniz series = %f\n", pi2());
}

