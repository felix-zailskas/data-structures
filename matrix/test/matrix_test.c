// SPDX-License-Identifier: MIT
// SPDX-FileCopyrightText: 2023 Felix Zailskas <felixzailskas@gmail.com>

#include "../matrix.h"

void matrix_test(void) {
  printf("Create empty matrix: \n");

  Matrix *m0 = make_matrix(7, 1);
  print_matrix(m0);

  printf("Copy matrix data from double[]\n");

  double a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix *m1 = copy_matrix(a, 3, 3);
  printf("m1:\n");
  print_matrix(m1);

  double a2[] = {1, 2, 3, 3.5, 4, 5, 6, 7};
  Matrix *m2 = copy_matrix(a2, 2, 4);
  printf("m2:\n");
  print_matrix(m2);

  printf("Transpose: m2 = m2t\n");
  Matrix *m2t = transpose_matrix(m2);
  print_matrix(m2t);

  double a3[] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix *m3 = copy_matrix(a3, 4, 2);
  printf("m3:\n");
  print_matrix(m3);

  printf("Multiplie m3 * m3t = m4\n");
  Matrix *m3t = transpose_matrix(m3);
  printf("m3t:\n");
  print_matrix(m3t);

  Matrix *m4 = mul_matrices(m3, m3t);
  printf("m4:\n");
  print_matrix(m4);

  double a5[] = {1, 2, 3, 3.5, 4, 5, 6, 7};
  Matrix *m5 = copy_matrix(a5, 2, 4);
  printf("m5:\n");
  print_matrix(m5);

  double a6[] = {1, 2, 3, 3.5, 4, 5, 6, 7};
  Matrix *m6 = copy_matrix(a6, 2, 4);
  printf("m6:\n");
  print_matrix(m6);

  printf("Add m5 + m6 = m7\n");
  Matrix *m7 = add_matrices(m5, m6);
  printf("m7:\n");
  print_matrix(m7);

  printf("Random matrix m8\n");
  Matrix *m8 = make_matrix(4, 5);
  m8 = random_matrix(m8);
  printf("m8:\n");
  print_matrix(m8);

  free_matrix(m0);
  free_matrix(m1);
  free_matrix(m2);
  free_matrix(m2t);
  free_matrix(m3);
  free_matrix(m3t);
  free_matrix(m4);
  free_matrix(m5);
  free_matrix(m6);
  free_matrix(m7);
  free_matrix(m8);
}

int main() {
  matrix_test();
  return 0;
}
