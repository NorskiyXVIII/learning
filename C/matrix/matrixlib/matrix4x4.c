#include "matrix4x4.h"

matrix4x4_t sum_matrix4x4(matrix4x4_t* mt1, matrix4x4_t* mt2) {
    matrix4x4_t ret;
    
    for (int i = 0; i < 4; i++) {
        ret.Column1[i] = mt1->Column1[i] + mt2->Column1[i];
        ret.Column2[i] = mt1->Column2[i] + mt2->Column2[i];
        ret.Column3[i] = mt1->Column3[i] + mt2->Column3[i];
        ret.Column4[i] = mt1->Column4[i] + mt2->Column4[i]; 
    }
    
    return ret;
}

void move_sum_matrix4x4(matrix4x4_t* res, matrix4x4_t* mt1, matrix4x4_t* mt2) {    
    for (int i = 0; i < 4; i++) {
        res->Column1[i] = mt1->Column1[i] + mt2->Column1[i];
        res->Column2[i] = mt1->Column2[i] + mt2->Column2[i];
        res->Column3[i] = mt1->Column3[i] + mt2->Column3[i];
        res->Column4[i] = mt1->Column4[i] + mt2->Column4[i]; 
    }
}

int print_matrix4x4(matrix4x4_t* mt) {
    printf("MATRIX[4X4] TYPE {\n");
    
    printf("\t");
    print_column(mt->Column1);
    printf(",\n");

    printf("\t");
    print_column(mt->Column2);
    printf(",\n");

    printf("\t");
    print_column(mt->Column3);
    printf(",\n");

    printf("\t");
    print_column(mt->Column4);
    printf(",\n");

    printf("}\n");

    return sum_matrix_to_int(mt);
}

int sum_matrix4x4_to_int(matrix4x4_t* mt) {
    int res = 0;
    
    res += sum_column_to_int(mt->Column1);
    res += sum_column_to_int(mt->Column2);
    res += sum_column_to_int(mt->Column3);
    res += sum_column_to_int(mt->Column4);
    
    return res;
}

void print_column4x4(int column[4]) {
    printf("[%d, %d, %d, %d]", column[0], column[1], column[2], column[3]);
}

int sum_column_to_int4x4(int column[4]) {
    return column[0] + column[1] + column[2] + column[3];
}