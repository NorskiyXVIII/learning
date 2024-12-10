#ifndef __NRSK__MATRIX__3X3__H__
#define __NRSK__MATRIX__3X3__H__

typedef struct matrix3x3 { int Column1[3], Column2[3], Column3[3]; } matrix3x3_t;

matrix3x3_t sum_matrix3x3(matrix3x3_t* mt1, matrix3x3_t* mt2);
void move_sum_matrix3x3(matrix3x3_t* res, matrix3x3_t* mt1, matrix3x3_t* mt2);
int print_matrix3x3(matrix3x3_t* mt);
int sum_matrix3x3_to_int(matrix3x3_t* mt);


void print_column3x3(int column[3]);
int sum_column_to_int3x3(int column[3]);

matrix3x3_t matrix3x3(matrix3x3_t* mt);
void swap_matrix3x3(matrix3x3_t* mt1, matrix3x3_t* mt2);

#endif