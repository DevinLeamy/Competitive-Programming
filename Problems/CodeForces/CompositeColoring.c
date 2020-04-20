#include<stdio.h>

int main() {
        int t;
        scanf("%d", &t);
        int prime[1001];
        for (int i = 0; i < 1001; i++) {
                prime[i] = 1;
        }
        for (int p=2; p*p<=1000; p++) {
                if (prime[p] == 1) {
                        for (int i=p*p; i<=1000; i += p) {
                                prime[i] = 0;
                        }
                }
        }
        for (int i = 0; i < t; i++) {
                int n, a;
                scanf("%d", &n);
                int nums[n];
                int color[n];
                for (int j = 0; j < n; j++) {
                        scanf("%d", &a);
                        nums[j] = a;
                        color[j] = -1;
                }
                int given = 0;
                int col = 1;
                int works = 0;
                for (int p = 2; p < 1001; p++) {
                        works = 0;
                        if (prime[p] == 1) {
                                for (int j = 0; j < n; j++) {
                                        if (color[j] == -1) {
                                                if (nums[j] % p == 0) {
                                                        works = 1;
                                                        color[j] = col;
                                                }
                                        }
                                }
                                if (works == 1) {
                                        col += 1;
                                }
                        }
                }
                printf("%d\n", (col-1));
                for (int j = 0; j < n; j++) {
                        printf("%d ", color[j]);
                }
                printf("\n");
        }
}
