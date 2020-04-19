#include<stdio.h>

int main() {
        int t;
        scanf("%d", &t);
        for(int i = 0; i < t; ++i) {
                int n, c, k, lacking = -1;
                int taken[100000] = { 0 };
                scanf("%d", &n);
                for(int j = 0; j < n; j++) {
                        scanf("%d", &c);
                        int found = 0;
                        for(int z = 0; z < c; ++z) {
                                scanf("%d", &k);
                                k--;
                                if (taken[k] == 0 && found == 0) {
                                        taken[k] = 1;
                                        found = 1;
                                }
                        }
                        if (found == 0) {
                                lacking = j;
                        }
                }
                if (lacking == -1) {
                        printf("OPTIMAL\n");
                } else {
                        int p = -1;
                        for (int j = n-1; j >= 0; --j) {
                                if (taken[j] == 0) {
                                        p = j;
                                        break;
                                }
                        }
                        printf("IMPROVE\n");
                        printf("%d %d\n", (lacking + 1), (p + 1));
                }

        }
}
