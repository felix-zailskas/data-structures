// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Felix Zailskas <felixzailskas@gmail.com>

#include "matrix.h"

// TODO: check all functions for correctness and memory leaks

/**
Creates a zero-initialized matrix of rows and columns matrix.
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of
n_cols doubles
*/
Matrix *make_matrix(int n_rows, int n_cols) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = n_rows;
  m->cols = n_cols;
  double **mat = (double **)malloc(n_rows * sizeof(double *));
  for (int i = 0; i < n_rows; i++) {
    mat[i] = (double *)malloc(n_cols * sizeof(double));
  }
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      mat[i][j] = 0;
    }
  }
  m->data = mat;
  return m;
}

/**
Generates a random double [a,b]
@param[in] minimun
@param[in] maximum
@return random double
*/
double rand_double(double a, double b) {
  double f = (double)rand() / RAND_MAX;
  return a + f * (a - b);
}

/**
Creates a matrix with the values from a data array.
@param[in] data an array of doubles, ordered row-wise
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return a pointer to an array of n_rows pointers to rows; a row is an array of
n_cols doubles
*/
Matrix *copy_matrix(double *data, int n_rows, int n_cols) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = n_rows;
  m->cols = n_cols;
  double **mat = (double **)malloc(n_rows * sizeof(double *));
  for (int i = 0; i < n_rows; i++) {
    mat[i] = (double *)malloc(n_cols * sizeof(double));
  }
  int k = 0;
  for (int i = 0; i < n_rows; i++) {
    for (int j = 0; j < n_cols; j++) {
      mat[i][j] = data[k];
      k += 1;
    }
  }
  m->data = mat;
  return m;
}

/**
Initializes a matrix with random data in a range of [0.0,1.0]
@param[in] data an array of doubles, ordered row-wise
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return initialized matrix
*/
Matrix *random_matrix(Matrix *a) {
  srand(time(NULL));
  double *rand_data = malloc(a->rows * a->cols * sizeof(double));
  for (int i = 0; i < (a->rows * a->cols); i++) {
    rand_data[i] = -1 * rand_double(0.0, 1.0);
  }
  return copy_matrix(rand_data, a->rows, a->cols);
}

/**
Creates a matrix with random data in a range of [0.0,1.0]
@param[in] n_rows number of rows
@param[in] n_cols number of columns
@return initialized matrix
*/
Matrix *make_rand_matrix(int n_rows, int n_cols) {
  Matrix *m = make_matrix(n_rows, n_cols);
  m = random_matrix(m);
  return m;
}

/**
Print a matrix.
@param[in] m the matrix to print
*/
void print_matrix(Matrix *m) {
  printf("{\n");
  for (int i = 0; i < m->rows; i++) {
    printf("[");
    for (int j = 0; j < m->cols; j++) {
      printf("%1.6f ", m->data[i][j]);
    }
    printf("]");
    printf("\n");
  }
  printf("}\n");
}

/**
Free a matrix.
@param[in] m the matrix to free
*/
void free_matrix(Matrix *m) {
  // todo: implement
  for (int i = 0; i < m->rows; i++) {
    free(m->data[i]);
  }
  free(m);
}

/**
Transpose a matrix.
@param[in] a the first operand
@return a new matrix whose elements are transposed
*/
Matrix *transpose_matrix(Matrix *a) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = a->cols;
  m->cols = a->rows;
  double **mata = (double **)malloc(a->rows * sizeof(double *));
  double **matm = (double **)malloc(m->rows * sizeof(double *));
  mata = a->data;
  for (int i = 0; i < m->rows; i++) {
    matm[i] = (double *)malloc(m->cols * sizeof(double));
  }
  for (int i = 0; i < a->cols; i++) {
    for (int j = 0; j < a->rows; j++) {
      matm[i][j] = mata[j][i];
    }
  }
  m->data = matm;
  return m;
}

/**
Multiplies two matrices.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that is the result of the multiplication of a * b
*/
Matrix *mul_matrices(Matrix *a, Matrix *b) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = a->rows;
  m->cols = b->cols;
  double **mata = (double **)malloc(a->rows * sizeof(double *));
  double **matb = (double **)malloc(b->rows * sizeof(double *));
  double **matm = (double **)malloc(m->rows * sizeof(double *));
  mata = a->data;
  matb = b->data;
  for (int i = 0; i < m->rows; i++) {
    matm[i] = (double *)malloc(m->cols * sizeof(double));
  }
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < b->cols; j++) {
      double sum = 0;
      for (int k = 0; k < a->cols; k++) {
        double product = mata[i][k] * matb[k][j];
        sum += product;
      }
      matm[i][j] = sum;
    }
  }
  m->data = matm;
  return m;
}

/**
Multiplies a matrix with a skalar.
@param[in] a the matrix
@param[in] x the skalar
@return a new matrix that is the result of the multiplication of a * x
*/
Matrix *mul_matrix_skalar(Matrix *a, double x) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = a->rows;
  m->cols = a->cols;
  double **matm = (double **)malloc(m->rows * sizeof(double *));
  for (int i = 0; i < m->rows; i++) {
    matm[i] = (double *)malloc(m->cols * sizeof(double));
  }
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      matm[i][j] = a->data[i][j] * x;
    }
  }
  m->data = matm;
  return m;
}

/**
Multiplies a matrix with another matrix elementwise of the same dimensions.
@param[in] a the first matrix
@param[in] b the second matrix
@return a new matrix that is the result of the multiplication of a * b
*/
Matrix *mul_matrix_element(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Matrices do not have the same dimensions function "
           "'mul_matrix_element' has failed");
    return NULL;
  }
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = a->rows;
  m->cols = a->cols;
  double **matm = (double **)malloc(m->rows * sizeof(double *));
  for (int i = 0; i < m->rows; i++) {
    matm[i] = (double *)malloc(m->cols * sizeof(double));
  }
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      matm[i][j] = a->data[i][j] * b->data[i][j];
    }
  }
  m->data = matm;
  return m;
}

/**
Subtracts a matrix from a skalar.
@param[in] a the matrix
@param[in] x the skalar
@return a new matrix that is the result of the multiplication of a * x
*/
Matrix *sub_skalar_from_matrix(Matrix *a, double x) {
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = a->rows;
  m->cols = a->cols;
  double **matm = (double **)malloc(m->rows * sizeof(double *));
  for (int i = 0; i < m->rows; i++) {
    matm[i] = (double *)malloc(m->cols * sizeof(double));
  }
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      matm[i][j] = 1 - a->data[i][j];
    }
  }
  m->data = matm;
  return m;
}

/**
Adds two matrices with the same dimensions.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that is the result of the sum of a + b
*/
Matrix *add_matrices(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Matrices do not have the same dimensions function 'add_matrices' "
           "has failed");
    return NULL;
  }
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = a->rows;
  m->cols = a->cols;
  double **mata = (double **)malloc(a->rows * sizeof(double *));
  double **matb = (double **)malloc(b->rows * sizeof(double *));
  double **matm = (double **)malloc(m->rows * sizeof(double *));
  mata = a->data;
  matb = b->data;
  for (int i = 0; i < m->rows; i++) {
    matm[i] = (double *)malloc(m->cols * sizeof(double));
  }
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      matm[i][j] = mata[i][j] + matb[i][j];
    }
  }
  m->data = matm;
  return m;
}

/**
Subtracts two matrices with the same dimensions.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that is the result of the sum of a + b
*/
Matrix *sub_matrices(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Matrices do not have the same dimensions function 'sub_matrices' "
           "has failed");
    return NULL;
  }
  Matrix *m = (Matrix *)malloc(sizeof(Matrix));
  m->rows = a->rows;
  m->cols = a->cols;
  double **mata = (double **)malloc(a->rows * sizeof(double *));
  double **matb = (double **)malloc(b->rows * sizeof(double *));
  double **matm = (double **)malloc(m->rows * sizeof(double *));
  mata = a->data;
  matb = b->data;
  for (int i = 0; i < m->rows; i++) {
    matm[i] = (double *)malloc(m->cols * sizeof(double));
  }
  for (int i = 0; i < m->rows; i++) {
    for (int j = 0; j < m->cols; j++) {
      matm[i][j] = mata[i][j] - matb[i][j];
    }
  }
  m->data = matm;
  return m;
}

/**
Calculates the square difference divided by two of two matrices with the same
dimensions.
@param[in] a the first operand
@param[in] b the second operand
@return a new matrix that contains the sqrdiff/2 of all elements
*/
Matrix *square_diff(Matrix *a, Matrix *b) {
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Matrices do not have the same dimensions function 'square_diff' "
           "has failed");
    return NULL;
  }
  Matrix *m;
  double diff[3];
  for (int i = 0; i < a->rows; i++) {
    for (int j = 0; j < a->cols; j++) {
      diff[i] =
          ((a->data[i][j] - b->data[i][j]) * (a->data[i][j] - b->data[i][j])) /
          2;
    }
  }
  m = copy_matrix(diff, 3, 1);
  return m;
}
