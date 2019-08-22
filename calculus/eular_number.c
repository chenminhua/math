/**
 * @ Author: Your name
 * @ Create Time: 2019-08-22 21:30:37
 * @ Modified by: Your name
 * @ Modified time: 2019-08-22 21:47:30
 * @ Description:
 */
#include <stdio.h>
#include <limits.h>
#include <math.h>

float eular1() {
    return pow(1 + 1./INT_MAX, INT_MAX);
}

/*using infinite series to calculate eular number */
float eluar2() {
    unsigned i = 1, n = 1e8;
    float e = 1;
    float fac_item = 1.;
    for (i = 1; i< n; i++){
        fac_item /= i;
        e += fac_item;
    }
    return e;
}

int main() {
    printf("calculus eular number by (1 + 1/n) ^ n = %f\n", eular1());
    printf("calculus eular number by infinite series (Maclaurin series) %f\n", eluar2());
    return 0;
}