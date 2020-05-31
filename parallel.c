double parallelMultiplyFloat(floatTYPE** matrixA, floatTYPE** matrixB, floatTYPE** matrixC, int dimension){
    struct timeval t0, t1;
    gettimeofday(&t0, 0);

    #pragma omp parallel for
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            for(int k=0; k<dimension; k++){
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    gettimeofday(&t1, 0);

    return getElapsedTime(t1, t0);
}


double parallelMultiplyDouble(doubleTYPE** matrixA, doubleTYPE** matrixB, doubleTYPE** matrixC, int dimension){
    struct timeval t0, t1;
    gettimeofday(&t0, 0);

    #pragma omp parallel for
    for(int i=0; i<dimension; i++){
        for(int j=0; j<dimension; j++){
            for(int k=0; k<dimension; k++){
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    gettimeofday(&t1, 0);

    return getElapsedTime(t1, t0);
}


void parallelMultiplyTest(int dimension){
    FILE* fp;
    fp = fopen("parallelMultiplyReport.txt", "a+");

    printf("----------------------------------\n");
    printf("Operation : Parallel Multiply          \n");
    printf("----------------------------------\n");
    printf("Dimension : %d\n", dimension);
    fprintf(fp, "----------------------------------\n");
    fprintf(fp, "Operation : Parallel Multiply          \n");
    fprintf(fp, "----------------------------------\n");
    fprintf(fp, "Dimension : %d\n", dimension);

    double* opmLatency = malloc(2 * sizeof(double));

    // double matrix
    doubleTYPE** doubleMatrixA = createDoubleSquareMatrix(dimension, 1.0);
    doubleTYPE** doubleMatrixB = createDoubleSquareMatrix(dimension, 1.0);
    doubleTYPE** doubleMatrixResult = createDoubleSquareMatrix(dimension, 0.0);
    opmLatency[0] = parallelMultiplyDouble(doubleMatrixA, doubleMatrixB, doubleMatrixResult, dimension);
    free(doubleMatrixResult);
    free(doubleMatrixA);
    free(doubleMatrixB);

    printf("Duration(double) : %f\n", opmLatency[0]);
    fprintf(fp, "Duration(double) : %f\n", opmLatency[0]);

    // float matrix
    floatTYPE** floatMatrixA = createFloatSquareMatrix(dimension, 1.0);
    floatTYPE** floatMatrixB = createFloatSquareMatrix(dimension, 1.0);
    floatTYPE** floatMatrixResult = createFloatSquareMatrix(dimension, 0.0);
    opmLatency[1] = parallelMultiplyFloat(floatMatrixA, floatMatrixB, floatMatrixResult, dimension);
    free(floatMatrixResult);
    free(floatMatrixA);
    free(floatMatrixB);

    printf("Duration(float) : %f\n\n", opmLatency[1]);
    fprintf(fp, "Duration(float) : %f\n\n", opmLatency[1]);

    fclose(fp);
    free(opmLatency);
}
