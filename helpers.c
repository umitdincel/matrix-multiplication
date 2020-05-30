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
