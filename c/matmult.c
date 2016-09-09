#include <stdio.h>
#include <math.h>


// Note the passing of a function reference as the last argument to bisect()

void read_dimension(int *row, int *col, char matrix_name);



void read_dimension(int *row, int *col, char matrix_name) {
  int a, b;
  printf( "Enter the dimension for Matrix %c (e.g 2,2):", matrix_name);
  scanf("%d,%d", row, col);

}

int main()
{
  // printf() displays the string inside quotation
  int dim_a_row, dim_a_col, dim_b_row, dim_b_col;
  char a = 'A', b = 'B';
  read_dimension(&dim_a_row, &dim_a_col, a);
  printf("Quantiteis are: %d, %d",dim_a_row, dim_a_col);
  return 0;
}

