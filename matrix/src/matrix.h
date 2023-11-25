#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include "time.h"

struct Matrix {
    int rows; // number of rows
    int cols; // number of columns
    double** data; // a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles
};
typedef struct Matrix Matrix;

/**
Creates a zero-initialized matrix of rows and columns matrix.
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles
*/
Matrix* make_matrix(int n_rows, int n_cols);

/**
Creates a matrix with the values from a data array.
@param[in] data an array of doubles, ordered row-wise
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of n_cols doubles
*/
Matrix* copy_matrix(double* data, int n_rows, int n_cols);

/**
Initializes a matrix with random data in a range of [0.0,1.0]
@param[in] data an array of doubles, ordered row-wise
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return initialized matrix
*/
Matrix* random_matrix(Matrix* a);

/**
Creates a matrix with random data in a range of [0.0,1.0]
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return initialized matrix
*/
Matrix* make_rand_matrix(int n_rows, int n_cols);

/**
Print a matrix.
@param[in] m the matrix to print
*/
void print_matrix(Matrix* m);

/**
Free a matrix.
@param[in] m the matrix to free
*/
void free_matrix(Matrix* m);

/**
Transpose a matrix.
@param[in] a the first operand
@return a new matrix whose elements are transposed
*/
Matrix* transpose_matrix(Matrix* a);

/**
Multiplies two matrices.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that is the result of the multiplication of a * b
*/
Matrix* mul_matrices(Matrix* a, Matrix* b);

/**
Multiplies a matrix with a skalar.
@param[in] a the matrix
@param[in] x the skalar
@return a new matrix that is the result of the multiplication of a * x
*/
Matrix* mul_matrix_skalar(Matrix* a, double x);

/**
Multiplies a matrix with another matrix elementwise of the same dimensions.
@param[in] a the first matrix
@param[in] b the second matrix
@return a new matrix that is the result of the multiplication of aij * bij
*/
Matrix* mul_matrix_element(Matrix* a, Matrix* b);

/**
Subtracts a skalar from a matrix.
@param[in] a the matrix
@param[in] x the skalar
@return a new matrix that is the result of the subtraction of aij - x
*/
Matrix* sub_skalar_from_matrix(Matrix* a, double x);

/**
Adds two matrices with the same dimensions.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that is the result of the sum of a + b
*/
Matrix* add_matrices(Matrix* a, Matrix* b);

/**
Subtracts two matrices with the same dimensions.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that is the result of the sum of a + b
*/
Matrix* sub_matrices(Matrix* a, Matrix* b);

/**
Calculates the square difference divided by two of two matrices with the same dimensions.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that contains the sqrdiff/2 of all elements
*/
Matrix* square_diff(Matrix* a, Matrix* b);

#endif
