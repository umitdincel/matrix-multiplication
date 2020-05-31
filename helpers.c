doubleTYPE** createDoubleSquareMatrix(int dimension, double value){
    doubleTYPE** matrix = malloc(dimension * sizeof(doubleTYPE*));

    for(int i=0; i<dimension; i++){
        matrix[i] = malloc(dimension * sizeof(doubleTYPE));
    }

    #pragma omp parallel for
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            matrix[i][j] = value;
        }
    }

    return matrix;
}


floatTYPE** createFloatSquareMatrix(int dimension, float value){
    floatTYPE** matrix = malloc(dimension * sizeof(floatTYPE*));

    for(int i=0; i<dimension; i++){
        matrix[i] = malloc(dimension * sizeof(floatTYPE));
    }

    #pragma omp parallel for
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            matrix[i][j] = value;
        }
    }

    return matrix;
}


double getElapsedTime(struct timeval t1, struct timeval t0){
    return (t1.tv_sec-t0.tv_sec) * 1.0f + (t1.tv_usec - t0.tv_usec) / 1000000.0f;
}

double getMFlops(int iterations, double elapsedTime){
    double Flops = iterations/elapsedTime;
    // Calculate Mega Flops Formula: F lops * 10raised to (-6).
    double mFlops = (double)Flops/1000000;

    return mFlops;
}