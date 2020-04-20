#include <stdio.h>

int main() {
        int n, m, k;
        int row, col, row1, col1;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i < k; i++) {
                scanf("%d%d", &row, &col);
        }
        for (int i = 0; i < k; i++) {
                scanf("%d%d", &row1, &col1);
        }
        if (n == 1 && m == 1) {
                printf("0");
                return 0;
        }
        if (n < m) {
                int count = n + m + (n * m) + n - 3;
                printf("%d\n", count);
                for (int i = 0; i < n-1; i++) {
                        printf("U");
                }
                for (int i = 0; i < m-1; i++) {
                        printf("L");
                }
                for (int i = 0; i < n; i++) {
                        for (int j = 0; j < m; j++) {
                                if (i % 2 == 0) {
                                        printf("R");
                                } else {
                                        printf("L");
                                }
                        }
                        if (i != n-1) {
                                printf("D");
                        }
                }
        } else {
                int count = m + n + (n * m) + m - 3;
                printf("%d\n", count);
                for (int i = 0; i < n-1; i++) {
                        printf("U");
                }
                for (int i = 0; i < m-1; i++) {
                        printf("L");
                }
                for (int i = 0; i < m; i++) {
                        for (int j = 0; j < n; j++) {
                                if (i % 2 == 0) {
                                        printf("D");
                                } else {
                                        printf("U");
                                }
                        }
                        if (i != m-1) {
                                printf("R");
                        }
                }
        }
}
