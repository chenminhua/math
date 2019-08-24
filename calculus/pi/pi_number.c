/**
 * @ Author: Minhua Chen
 * @ Create Time: 2019-08-22 21:54:29
 * @ Modified by: Minhua Chen
 * @ Modified time: 2019-08-24 09:57:20
 * @ Description:
 */
#include <stdio.h>
#include <stdlib.h>
#define LOOP_N 8192000000

/*calculus pi by Monte Carlo method */
double pi1() {
    long k = 0, n = LOOP_N;
    double i, j;
    for (long m = 0; m < n; m++) {
        i = (double)rand() / RAND_MAX;
        j = (double)rand() / RAND_MAX;
        if (i * i + j * j < 1.) k++;
    }

    return ((double)k/n )*4;
}

/*calculus pi by Leibniz series */
double pi2() {
    double pi_qv = 1.0;
    int flag = -1;
    for (long i = 1; i < LOOP_N; i++) {
        pi_qv += flag * (1./(2 * i + 1));
        flag = -flag;
    }
    return pi_qv * 4;
}

int main() {
    // printf("calculate pi by Monte Carlo %f\n", pi1());
    printf("calculate pi by Leibniz series = %f\n", pi2());
}

