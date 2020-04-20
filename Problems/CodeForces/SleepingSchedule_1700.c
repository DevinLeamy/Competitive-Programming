#include<stdio.h>

int n, h, l, r, a;
int max(int a, int b) {
        if (a >= b) {
                return a;
        }
        return b;
}
int points(int t) {
        if (l <= t && t <= r) {
                return 1;
        }
        return 0;
}
int main() {
        scanf("%d%d%d%d", &n, &h, &l, &r);
        int nums[n];
        for (int i = 0; i < n; i++) {
                scanf("%d", &a);
                nums[i] = a;
        }
        int dp[n][h];
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < h; j++) {
                        dp[i][j] = -1;
                }
        }
        dp[0][nums[0]] = points(nums[0]);
        dp[0][nums[0] - 1] = points(nums[0] - 1);
        for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < h; j++) {
                        int sleep = (j + nums[i+1]) % h;
                        int bSleep = sleep - 1;
                        if (bSleep == -1) {
                                bSleep = h-1;
                        }
                        if (dp[i][j] != -1) {
                                int point[2] = {points(sleep), points(bSleep)};
                                dp[i+1][sleep] = max(dp[i+1][sleep], dp[i][j] + point[0]);
                                dp[i+1][bSleep] = max(dp[i+1][bSleep], dp[i][j] + point[1]);
                        }
                }
        }
        int max = 0;
        for (int i = 0; i < h; i++) {
                if (dp[n-1][i] > max) {
                        max = dp[n-1][i];
                }
        }
        printf("%d", max);
}

