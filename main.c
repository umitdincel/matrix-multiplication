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


int main(int argc, char* argv[]){
    for(int dimension=MIN_DIM; dimension<=MAX_DIM; dimension+=DIM_STEP){
        sequentialMultiplyTest(dimension);
    }

    for(int dimension=MIN_DIM; dimension<=MAX_DIM; dimension+=DIM_STEP){
        parallelMultiplyTest(dimension);
    }

    return 0;
}
