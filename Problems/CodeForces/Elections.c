#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
        return ( *(int*)a - *(int*)b );
}

int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int poles[m][n];
        int sums[n];
        int diffs[m];
        for (int i = 0; i < n; i++) {
                sums[i] = 0;
        }
        for (int i = 0; i < m; i++) {
                int a;
                diffs[i] = -1;
                for (int j = 0; j < n; j++) {
                        scanf("%d", &a);
                        poles[i][j] = a;
                        sums[j] += a;
                }
        }
        int minP = m+1;
        int best = -1;

        for (int i = 0; i < n-1; i++) {
                int val[m];
                int newDiffs[m];
                for (int j = 0; j < m; j++) {
                        val[j] = poles[j][i] - poles[j][n-1];
                        newDiffs[j] = 0;
                }

                qsort(val, m, sizeof(int), cmpfunc);

                int count = 0;
                int bc = sums[n-1] - sums[i];
                while (bc > 0) {
                        newDiffs[count] = val[count];
                        bc += val[count];
                        count++;
                }
                if (count < minP) {
                        minP = count;
                        best = i;
                        for (int j = 0; j < count; j++) {
                                diffs[j] = newDiffs[j];
                        }
                }
        }
        printf("%d\n", minP);

        for (int i = 0; i < m; i++) {
                int diff = poles[i][best] - poles[i][n-1];
                for (int j = 0; j < minP; j++) {
                        if (diffs[j] == diff) {
                                printf("%d ", (i + 1));
                                diffs[j] = 20000;
                                break;
                        }
                }
        }

}
