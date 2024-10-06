#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 256

void multiplyMatrix(double m1[][N], double m2[][N])
{
    double result[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;

            for (int k = 0; k < N; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }

        }

    }
}

// Driver code
int main()
{

    double m1[N][N];
    double m2[N][N];
    for(int i = 0; i < N;i++) {
    	for(int j = 0; j < N;j++) {

    		m1[i][j]=rand()%10;
    		m2[i][j]=rand()%10;
    	}
    }

    // if coloumn of m1 not equal to rows of m2
    if (N != N) {
        printf("The number of columns in Matrix-1 must be "
               "equal to the number of rows in "
               "Matrix-2\n");
        printf("Please update MACROs value according to "
               "your array dimension in "
               "#define section\n");

        exit(EXIT_FAILURE);
    }

    clock_t start_time = clock();
    multiplyMatrix(m1, m2);
    double elapsed_time = (double)(clock() - start_time) / CLOCKS_PER_SEC;
  printf("Done in %f seconds\n", elapsed_time);

    return 0;
}
