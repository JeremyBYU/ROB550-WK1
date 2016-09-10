#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Note the passing of a function reference as the last argument to bisect()

void read_dimension(int *row, int *col, char matrix_name);
int read_file(char *fileName, double** mat, int row, int col);
double** create_array(int row, int col);

double** create_array(int row, int col) {
  int i;
  double** matrix;

  matrix = (double **) malloc(row * sizeof(*double));
  for(i=0; i < col; i++) {
    matrix[i] = (double *) malloc(col * sizeof(double));
  }
  return matrix;
}

void read_dimension(int *row, int *col, char matrix_name)
{
  printf("\nEnter the dimension for Matrix %c (e.g 2,2):", matrix_name);
  scanf("%d,%d", row, col);
  if (*row < 1 || *row > 9999 || *col < 1 || *col > 9999)
  {
    fprintf(stderr, "Values must be integers less than 4 digits!\n");
    exit(0);
  }
}

int read_file(char *fileName, double** mat, int row, int col)
{
  char buffer[1024];
  char *record, *line;
  int i = 0, j = 0;
  // double mat[100][100];
  FILE *fstream = fopen(fileName, "r");
  if (fstream == NULL)
  {
    fprintf(stderr, "\n file opening failed ");
    return -1;
  }
  while ((line = fgets(buffer, sizeof(buffer), fstream)) != NULL)
  {
    record = strtok(line, ",");
    while (record != NULL)
    {
      printf("record : %s", record); //here you can put the record into the array as per your requirement.
      mat[i][j++] = atof(record);
      record = strtok(NULL, ",");
    }
    ++i;
  }
  printf("stuff");
  return 1;
  // i == number of rows, j == number of columns
}

int main()
{
  // printf() displays the string inside quotation
  int dim_a_row, dim_a_col, dim_b_row, dim_b_col;
  char a = 'A', b = 'B';
  float** matrix_a, matrix_b;
  char* aFile = "A.csv";
  read_dimension(&dim_a_row, &dim_a_col, a);
  matrix_a = create_array(dim_a_row, dim_a_col);
  read_file(aFile, dim_a_row, dim_a_col);

  read_dimension(&dim_b_row, &dim_b_col, b);
  // printf("Quantities are: %d, %d\n",dim_a_row, dim_a_col);
  return 0;
}
