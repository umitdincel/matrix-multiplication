#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <pthread.h>
#include <omp.h>
#include <math.h>

typedef double doubleTYPE;
typedef float floatTYPE;

#include "helpers.c"
#include "sequential.c"
#include "parallel.c"

#define MIN_DIM 1000
#define MAX_DIM 5000
#define DIM_STEP 1000
#define MAX_MFLOPS 228889


int main(int argc, char* argv[]){
    struct timeval t0, t1;
    double elapsed, mFlops, flopPercentage;

    gettimeofday(&t0, 0);
    for(int dimension=MIN_DIM; dimension<=MAX_DIM; dimension+=DIM_STEP){
        sequentialMultiplyTest(dimension);
    }
    gettimeofday(&t1, 0);

    elapsed = getElapsedTime(t1, t0);
    mFlops = getMFlops(440000000, elapsed);
    flopPercentage = (float)mFlops / MAX_MFLOPS * 100.0;

    printf("Total duration: %f\n", elapsed);
    printf("mFlops: %f\n", mFlops);
    printf("Percentage of mFlop/s: %%%d\n\n\n", (int)flopPercentage);

    gettimeofday(&t0, 0);
    for(int dimension=MIN_DIM; dimension<=MAX_DIM; dimension+=DIM_STEP){
        parallelMultiplyTest(dimension);
    }
    gettimeofday(&t1, 0);

    elapsed = getElapsedTime(t1, t0);
    mFlops = getMFlops(440000000, elapsed);
    flopPercentage = (float)mFlops / MAX_MFLOPS * 100.0;

    printf("Total duration: %f\n", elapsed);
    printf("mFlops: %f\n", mFlops);
    printf("Percentage of mFlop/s: %%%d\n\n\n", (int)flopPercentage);

    return 0;
}
