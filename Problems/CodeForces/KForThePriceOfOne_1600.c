#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
        return ( *(int*)a - *(int*)b );
}
int max(int a, int b) {
        if (a >= b) {
                return a;
        }
        return b;
}
int main() {
        int t;
        scanf("%d", &t);
        for (int q = 0; q < t; q++) {
                int n, p, k, a;
                scanf("%d%d%d", &n, &p, &k);
                int nums[n];
                long long pSum[n+1];
                for (int j = 0; j < n; j++) {
                        scanf("%d", &a);
                        nums[j] = a;
                }
                qsort(nums, n, sizeof(int), cmpfunc);
                pSum[0] = 0;
                for (int j = 1; j <= n; j++) {
                        pSum[j] = pSum[j-1] + nums[j-1];
                }
                int b = 0;
                for (int i = 0; i < k; i++) {
                        int mon = p;
                        if (mon < pSum[i]) {
                                break;
                        }
                        mon -= pSum[i];
                        int cur = (i + k) - 1;
                        int count = i;
                        while (cur < n && mon >= nums[cur]) {
                                mon -= nums[cur];
                                count += k;
                                cur += k;
                        }
                        b = max(b, count);
                }
                printf("%d\n", b);
        }
}
