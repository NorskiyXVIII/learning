#include <stdio.h>
#include "matrixlib/matrix3x3.h"


int main() {
    matrix3x3_t mtr1 = {
        {4, 4, 4},
        {3, 3, 3},
        {2, 2, 2}
    };

    matrix3x3_t mtr2 = {
        {4, 4, 4},
        {3, 3, 3},
        {2, 2, 2}
    };

    print_matrix3x3(&mtr1);
    print_matrix3x3(&mtr2);
    
    matrix3x3_t mtr3 = sum_matrix3x3(&mtr1, &mtr2);

    print_matrix3x3(&mtr3);
    swap_matrix3x3(&mtr3, &mtr2);

    print_matrix3x3(&mtr3);
    print_matrix3x3(&mtr2);
    
    return 0;
}