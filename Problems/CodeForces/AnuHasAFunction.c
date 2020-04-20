#include<stdio.h>
#include<math.h>
int main() {
        long long n, a;
        scanf("%lli", &n);
        long long nums[n];
        for (int i = 0; i < n; i++) {
                scanf("%lli", &a);
                nums[i] = a;
        }
        long long numSet[64];
        for (int i = 0; i < 64; i++) {
                numSet[i] = 0;
        }
        for (int i = 0; i < n; i++) {
                long long cur = nums[i];
                int bit = 0;
                while (cur) {
                        numSet[bit] += cur & 1;
                        cur >>= 1;
                        bit++;
                }
        }
        int largestUniqueBit = -1;
        for (int i = 63; i >= 0; i--) {
                if (numSet[i] == 1) {
                        largestUniqueBit = i;
                        break;
                }
        }
        if (largestUniqueBit == -1) {
                for (int i = 0; i < n; i++) {
                        printf("%lli ", nums[i]);
                }
        } else {
                int index = -1;
                for (int i = 0; i < n; i++) {
                        if (nums[i] >= (long long)pow(2, largestUniqueBit) && ((nums[i] >> largestUniqueBit) & 1)) {
                                printf("%lli ", nums[i]);
                                index = i;
                        }
                }
                for (int i = 0; i < n; i++) {
                        if (i != index) {
                                printf("%lli ", nums[i]);
                        }
                }
        }
}
// AnuHasAFunction.c
