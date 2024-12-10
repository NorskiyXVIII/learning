#include "matrix3x3.h"

matrix3x3_t sum_matrix3x3(matrix3x3_t* mt1, matrix3x3_t* mt2) {
    matrix3x3_t ret;
    
    for (int i = 0; i < 3; i++) {
        ret.Column1[i] = mt1->Column1[i] + mt2->Column1[i];
        ret.Column2[i] = mt1->Column2[i] + mt2->Column2[i];
        ret.Column3[i] = mt1->Column3[i] + mt2->Column3[i]; 
    }
    
    return ret;
}

void move_sum_matrix3x3(matrix3x3_t* res, matrix3x3_t* mt1, matrix3x3_t* mt2) {    
    for (int i = 0; i < 3; i++) {
        res->Column1[i] = mt1->Column1[i] + mt2->Column1[i];
        res->Column2[i] = mt1->Column2[i] + mt2->Column2[i];
        res->Column3[i] = mt1->Column3[i] + mt2->Column3[i];
    }
}

int print_matrix3x3(matrix3x3_t* mt) {
    printf("MATRIX[3X3] TYPE {\n");
    
    printf("\t");
    print_column(mt->Column1);
    printf(",\n");

    printf("\t");
    print_column(mt->Column2);
    printf(",\n");

    printf("\t");
    print_column(mt->Column3);
    printf("\n");

    printf("}\n");

    return sum_matrix_to_int(mt);
}

int sum_matrix3x3_to_int(matrix3x3_t* mt) {
    int res = 0;
    
    res += sum_column_to_int(mt->Column1);
    res += sum_column_to_int(mt->Column2);
    res += sum_column_to_int(mt->Column3);

    return res;
}

void print_column3x3(int column[3]) {
    printf("[%d, %d, %d]", column[0], column[1], column[2]);
}

int sum_column_to_int3x3(int column[3]) {
    return column[0] + column[1] + column[2];
}

matrix3x3_t matrix3x3(matrix3x3_t* mt) {
    return *mt;
}
void swap_matrix3x3(matrix3x3_t* mt1, matrix3x3_t* mt2) {
    matrix3x3_t tmp = matrix3x3(mt1);

    *mt1 = matrix3x3(mt2);
    *mt2 = matrix3x3(&tmp);
}