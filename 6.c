#include <stdio.h>
#include <limits.h>

void MCM(long int p[], long int n) {
    long int m[10][10];
    long int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = LONG_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    printf("-------------------------------------------\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            if (i < j)
                printf("%ld\t", m[i][j]);
            else if (i == j)
                printf("0\t");
            else
                printf("--\t");
        }
        printf("\n");
    }
}

int main() {
    long int n;
    printf("Enter the number of matrices: ");
    scanf("%ld", &n);

    long int arr[n];
    printf("Enter the dimensions array (length %ld): ", n);
    for (long int i = 0; i < n; i++) {
        scanf("%ld", &arr[i]);
    }

    MCM(arr, n);

    return 0;
}
