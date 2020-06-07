#include<stdio.h>
#include<math.h>

int main() {
        int t;
        scanf("%d", &t);
        for (int i = 0; i < t; i++) {
                int c;
                scanf("%d", &c);
                long long a;
                long long cMax = 9223372036854775807 *  -1;
                int bitMax = 0;
                for (int j = 0; j < c; j++) {
                        scanf("%lli", &a);
                        if (a >= cMax) {
                                cMax = a;
                        } else {
                                long long diff = cMax - a;
                                int bitDiff = (int)log2(diff)+1;
                                // printf("%lli %d\n", diff, bitDiff);
                                if (bitDiff > bitMax) {
                                        bitMax = bitDiff;
                                }
                        }
                }
                printf("%d\n", bitMax);
        }
}
