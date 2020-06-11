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
        int count = n + m + (n * (m-1)) + n - 3;
        printf("%d\n", count);
        for (int i = 0; i < n-1; i++) {
                printf("U");
        }
        for (int i = 0; i < m-1; i++) {
                printf("L");
        }
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m-1; j++) {
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
}
