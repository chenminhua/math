#include<stdio.h>
#include<cuda.h>
#include<cuda_runtime.h>

#define BLOCK_NUM 32   //块数量
#define THREAD_NUM 256 // 每个块中的线程数
#define LOOP_N BLOCK_NUM * THREAD_NUM * 1000000

__global__ void pi2(double* result) {
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
    result[bid*THREAD_NUM+tid] = tmp;
}

int main(){
    double *sum, *result;
    double pi_v = 1;

    // allocate host memory
    sum = (double*) malloc(sizeof(double) * BLOCK_NUM * THREAD_NUM);

    // Allocate device memory
    cudaMalloc((void **)&result, sizeof(double) * BLOCK_NUM * THREAD_NUM);
    
    // Execute kernels
    pi2<<<BLOCK_NUM,THREAD_NUM>>>(result);

    // Transfer output from device memory to host
    cudaMemcpy(sum, result, sizeof(double)*BLOCK_NUM*THREAD_NUM, cudaMemcpyDeviceToHost);

    for (int i = 0; i < BLOCK_NUM * THREAD_NUM; i++) {
        pi_v += sum[i];
    }

    printf("calculate %.10f\n", pi_v*4);

    cudaFree(result);
    free(sum);
}
