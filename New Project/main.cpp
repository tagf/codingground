#include <stdio.h>
#include <stdlib.h>

int ** transpose(const int * const * m, unsigned rows, unsigned cols) {
    unsigned int i, j;
    int **a;
    a = (int **) malloc(sizeof(int) * cols);
    for (i = 0; i < cols; ++i) {
        a[i] = (int *) malloc(sizeof(int) * rows);
        for (j = 0; j < rows; ++j) {
            a[i][j] = m[j][i];
        }
    }
    return a;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int i, j;
    int **a, **transposed;
    a = (int **) malloc(sizeof(int) * n);
    for (i = 0; i < n; ++i) {
        a[i] = (int *) malloc(sizeof(int) * m);
        for (j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    transposed = transpose(a, n, m);
    for (i = 0; i < n; ++i) {
        free(a[i]);
    }
    free(a);
    

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d ", transposed[i][j]);
        }
    }
    for (i = 0; i < m; ++i) {
        free(transposed[i]);
    }
    free(transposed);
    return 0;
}