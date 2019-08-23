#include<stdio.h>
#include<cuda.h>
#include<cuda_runtime.h>

#define BLOCK_NUM 32   //块数量
#define THREAD_NUM 256 // 每个块中的线程数
#define LOOP_N BLOCK_NUM * THREAD_NUM * 1000000

__global__ void leib_pi(double* g_sum) {
    const int tid = threadIdx.x;
    const int bid = blockIdx.x;
    double tmp = 0;
    int flag = -1;
    int idx = bid * THREAD_NUM + tid;
    int start = idx * 100000 + 1;
    int end = start + 100000;
    for (int i = start; i < end; i++) {
        tmp += flag * (1./(2 * i + 1));
        flag = -flag;
    }
    g_sum[bid*THREAD_NUM+tid] = tmp;
}

int main(){
    double *h_sum, *g_sum;
    double pi_v = 1;

    // allocate host memory
    h_sum = (double*) malloc(sizeof(double) * BLOCK_NUM * THREAD_NUM);

    // Allocate device memory
    cudaMalloc((void **)&g_sum, sizeof(double) * BLOCK_NUM * THREAD_NUM);

    // Execute kernels
    leib_pi<<<BLOCK_NUM,THREAD_NUM>>>(g_sum);

    // Transfer output from device memory to host
    cudaMemcpy(h_sum, g_sum, sizeof(double)*BLOCK_NUM*THREAD_NUM, cudaMemcpyDeviceToHost);

    for (int i = 0; i < BLOCK_NUM * THREAD_NUM; i++) {
        pi_v += h_sum[i];
    }

    printf("calculate %.10f\n", pi_v*4);

    cudaFree(g_sum);
    free(h_sum);
}