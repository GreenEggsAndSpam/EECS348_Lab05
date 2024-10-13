
/* 
Name: Vrishank Kulkarni 
ID: 3115417
Class: EECS 348 lab 05
Lab time: Wednesday 1-2:50

Objectives:
addMatrices: This function should take two matrices as input and return their sum.

multiplyMatrices: This function should take two matrices as input and return their
product.

transposeMatrix: This function should take a matrix as input and return its transpose.
 
 printMatrix: print the matrix in a user-friendly format

 error checking: check if the dimensions are valid for addition and multiplication 
 */

#include <stdio.h>
#define SIZE 5

//function to check if matrix addition is valid (both matrices need to be the same size
int isAddValid(int rows1, int cols1, int rows2, int cols2) {
    if (rows1 == rows2 && cols1 == cols2) {
        return 1;  //valid
    }
    return 0;  //invalid
}

//function to check if matrix multiplication is valid 
//the number of columns of the first matrix should equal the number of rows of the second matrix
int isMultiplyValid(int rows1, int cols1, int rows2, int cols2) {
    if (cols1 == rows2) {
        return 1;  //valid
    }
    return 0;  //invalid
}

//function to add two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //goes through the rows
    for (int row = 0; row < SIZE; row++) {
        //goes through the columns
        for (int column = 0; column < SIZE; column++) {
            result[row][column] = m1[row][column] + m2[row][column];
        }
    }
}

//function to multiply two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    //initialize the result matrix with zeros
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            result[row][column] = 0;
        }
    }

    //calculate matrix multiplication
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            for (int k = 0; k < SIZE; k++) {
                //take the sum of each elements from the row multiplied by each element from the column from the second matrix
                result[row][column] += m1[row][k] * m2[k][column];
            }
        }
    }
}

//function to transpose a matrix
void transposeMatrix(int m[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            result[column][row] = m[row][column];  //swap row and column
        }
    }
}

//function to print a matrix
void printMatrix(int m[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int column = 0; column < SIZE; column++) {
            printf("%4d ", m[row][column]);  //print each element with some spacing
        }
        printf("\n");
    }
    printf("\n");  //add extra space between matrices
}


int main() {
    //define two matrices m1 and m2
    int m1[SIZE][SIZE] = {
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9,  10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10,  9,  8,  7,  6},
        {5,   4,  3,  2,  1}
    };

    int result[SIZE][SIZE];  //store results of operations

    //check if addition is valid
    if (isAddValid(SIZE, SIZE, SIZE, SIZE)) {
        printf("Sum of matrices:\n");
        addMatrices(m1, m2, result);
        printMatrix(result);
    } else {
        printf("Matrix addition is not valid!\n");
    }

    //check if multiplication is valid
    if (isMultiplyValid(SIZE, SIZE, SIZE, SIZE)) {
        printf("Product of matrices:\n");
        multiplyMatrices(m1, m2, result);
        printMatrix(result);
    } else {
        printf("Matrix multiplication is not valid!\n");
    }

    //transpose of the first matrix
    printf("Transpose of the first matrix (m1):\n");
    transposeMatrix(m1, result);
    printMatrix(result);

    return 0;
}


