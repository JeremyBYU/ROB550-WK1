#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <inttypes.h>


// Note the passing of a function reference as the last argument to bisect()

void read_dimension(int *row, int *col, char matrix_name);
int read_file(char *fileName, double** mat, int row, int col);
double** create_array(int row, int col);
void print_matrix(char* fileName, double** mat, int row, int col);
double mult_row_col(double** mat1, double** mat2, int row, int col, int size);
double** dot_product(double** mat1, double** mat2, int dim1_row, int dim1_col, int dim2_row, int dim2_col);
int dim_compatible(int mat1_col, int mat2_row);
void print_file(char* fileName, double** mat, int row, int col);

void print_file(char* fileName, double** mat, int row, int col) {
  FILE *fp;
  int i,j;
 
  fp=fopen(fileName,"w+");
  // fprintf(fp,"Student Id, Physics, Chemistry, Maths");
  for(i = 0; i < row; i++) {
    for(j = 0;j < col; j++) {
      fprintf(fp, "%f, ", mat[i][j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
}
int64_t utime_now (void){
	struct timeval tv;
	gettimeofday (&tv, NULL);
	return (int64_t) tv.tv_sec * 1000000 + tv.tv_usec;
}
int dim_compatible(int mat1_col, int mat2_row) {
  return mat1_col == mat2_row;
}

double** dot_product(double** mat1, double** mat2, int dim1_row, int dim1_col, int dim2_row, int dim2_col) {
  int i, j;
  double** product = create_array(dim1_row, dim2_col);
  for(i = 0; i < dim1_row; i++) {
    for(j = 0; j <  dim2_col; j++) {
      double val = mult_row_col(mat1, mat2, i, j, dim1_col);
      product[i][j] = val;
      // printf("%f", val);
    }
  }
  return product;
}

void print_matrix(char* fileName, double** mat, int row, int col) {
  int i, j;
  for(i = 0; i < row; i++) {
    for(j = 0; j < col; j++) {
      printf("%f, ", mat[i][j]);
    }
    printf("\n");
  }
}
// Performs the dot product of on row and one column that are of the same length (size)
// The row is taken from the specified row (row) in mat1 and the column comes from the
// speci
double mult_row_col(double** mat1, double** mat2, int row, int col, int size) {
  int i;
  double sum = 0;
  for(i = 0; i < size; i++) {
    sum += mat1[row][i] * mat2[i][col];
  }
  return sum;
}

double** create_array(int row, int col) {
  int i;
  double** matrix;

  matrix = (double **) malloc(row * sizeof(double*));
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
    j = 0;
    record = strtok(line, ",");
    while (record != NULL)
    {
      // printf("%s;", record); //here you can put the record into the array as per your requirement.
      mat[i][j++] = atof(record);
      record = strtok(NULL, ",");
      // Check for column overflow
      if (j > col) {
        fprintf(stderr, "ERROR! Matrix %s does not have the same user supplied column dimensions!\n", fileName);
        exit(0);
      }
    }
    // printf("\n");
    ++i;
    // Check for row overflow
    if (i > row) {
      fprintf(stderr, "ERROR! Matrix %s does not have the same user supplied row dimensions!\n", fileName);
      exit(0);
    }
  }
  // check that file matrix size equals correct dimensions
  if (i == row && j == col) {
    return 1;
  } else {
    fprintf(stderr, "ERROR! Matrix %s does not have the same user supplied dimensions!\n", fileName);
    exit(0);
  }
  // i == number of rows, j == number of columns
}

int main(int argc, char **argv)
{
  if(argc < 2) {
    fprintf(stderr, "Please specify and outfile in arguments (e.g. matmult C.csv)");
    exit(0);
  }
  // printf() displays the string inside quotation
  int dim_a_row, dim_a_col, dim_b_row, dim_b_col;
  char a = 'A', b = 'B';
  double ** matrix_a, ** matrix_b, ** product;
  char* aFile = "A.csv"; 
  char* bFile = "B.csv";
  
  int64_t sTime;

  read_dimension(&dim_a_row, &dim_a_col, a);
  matrix_a = create_array(dim_a_row, dim_a_col);
  read_file(aFile, matrix_a, dim_a_row, dim_a_col);

  // print_matrix("C.csv", matrix_a, dim_a_row, dim_a_col);

  read_dimension(&dim_b_row, &dim_b_col, b);
  matrix_b = create_array(dim_b_row, dim_b_col);
  read_file(bFile, matrix_b, dim_b_row, dim_b_col);
  // print_matrix("C.csv", matrix_b, dim_b_row, dim_b_col);
  sTime = utime_now();
  product = dot_product(matrix_a, matrix_b, dim_a_row, dim_a_col, dim_b_row, dim_b_col);
  printf("\nElapsed Time: %" PRId64 "\n", utime_now() - sTime);
  // print_matrix("C.csv", product, dim_a_row, dim_b_col);
  print_file(argv[1], product, dim_a_row, dim_b_col);
  return 0;
}
