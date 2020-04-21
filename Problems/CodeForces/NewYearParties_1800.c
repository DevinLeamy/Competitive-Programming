#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
        return ( *(int*)a - *(int*)b );
}

int main() {
        int n, a;
        scanf("%d", &n);
        int nums[n];
        int oc[n+2];
        int largest = -1;
        for (int i = 0; i < n+2; i++) {
                oc[i] = -1;
        }
        for (int i = 0; i < n; i++) {
                scanf("%d", &a);
                nums[i] = a;
                if (a > largest) {
                        largest = a;
                }
        }

        qsort(nums, n, sizeof(int), cmpfunc);

        //Max
        int maxC = 0;
        for (int i = 0; i < n; i++) {
                int cur = nums[i];
                if (oc[cur-1] == -1) {
                        oc[cur-1] = 1;
                        maxC++;
                } else if (oc[cur] == -1) {
                        oc[cur] = 1;
                        maxC++;
                } else if (oc[cur+1] == -1) {
                        oc[cur+1] = 1;
                        maxC++;
                }
        }

        //Min
        for (int i = 0; i < n+2; i++) {
                oc[i] = 0;
        }
        for (int i = 0; i < n; i++) {
                oc[nums[i]]++;
        }
        int minC = 0;
        for (int i = 0; i <= n; i++) {
                if (oc[i] > 0) {
                        minC++;
                        i += 2;
                }
        }
        printf("%d %d", minC, maxC);
}
