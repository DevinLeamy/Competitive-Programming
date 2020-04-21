#include<stdio.h>
#include <stdlib.h>

long long cmpfunc (const void * a, const void * b) {
   return ( *(long long*)a - *(long long*)b );
}

int main() {
        long long n, a, b, k, h;
        scanf("%lli%lli%lli%lli", &n, &a, &b, &k);
        long long nums[n];
        long long count = 0;
        for (int i = 0; i < n; i++) {
                scanf("%lli", &h);
                long long temp = h;
                if (h > (a + b)) {
                        h %= (a + b);
                        if (h == 0) {
                                h += b;
                                nums[i] = h / a;
                                if (h % a != 0) {
                                        nums[i]++;
                                }
                        } else {
                                if (h <= a) {
                                        nums[i] = 0;
                                } else {
                                        h -= a;
                                        nums[i] = h / a;
                                        if (h % a != 0) {
                                                nums[i]++;
                                        }
                                }
                        }
                } else {
                        if (h <= a) {
                                nums[i] = 0;
                        } else {
                                h -= a;
                                nums[i] = h / a;
                                if (h % a != 0) {
                                        nums[i]++;
                                }
                        }
                }
        }
        qsort(nums, n, sizeof(long long), cmpfunc);
        int cur = 0;
        while (1) {
                if (k >= nums[cur]) {
                        k -= nums[cur];
                        count++;
                } else {
                        break;
                }
                cur++;
        }

        printf("%lli", count);
}
