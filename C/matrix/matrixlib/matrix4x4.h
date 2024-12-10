#ifndef __NRSK__MATRIX__4X4__H__
#define __NRSK__MATRIX__4X4__H__

typedef struct matrix4x4 { int Column1[4], Column2[4], Column3[4], Column4[4]; } matrix4x4_t;

matrix4x4_t sum_matrix4x4(matrix4x4_t* mt1, matrix4x4_t* mt2);
void move_sum_matrix4x4(matrix4x4_t* res, matrix4x4_t* mt1, matrix4x4_t* mt2);
int print_matrix4x4(matrix4x4_t* mt);
int sum_matrix4x4_to_int(matrix4x4_t* mt);


void print_column4x4(int column[4]);
int sum_column_to_int4x4(int column[4]);


#endif