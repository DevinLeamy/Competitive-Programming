#include <stdio.h>

int min(int a, int b) {
        if (a <= b) {
                return a;
        }
        return b;
}

int main() {
        int n, imp = 0, a;
        scanf("%d", &n);
        int nums[n];
        for (int i = 0; i < n; i++) {
                scanf("%d", &a);
                if (a == 0) {
                        nums[i] = 0;
                } else if (a % 2 == 0) {
                        nums[i] = 2;
                } else {
                        nums[i] = 1;
                        imp++;
                }
        }
        int impTP = (n / 2) + (n % 2);
        impTP -= imp;
        int dp[n][impTP+1][2];
        for (int i = 0; i < n; i++) {
                for (int j = 0; j <= impTP; j++) {
                        dp[i][j][0] = 101;
                        dp[i][j][1] = 101;
                }
        }

        if (nums[0] == 0) {
                dp[0][impTP][0] = 0;
                dp[0][impTP-1][1] = 0;
        } else if (nums[0] == 1) {
                dp[0][impTP][1] = 0;
        } else {
                dp[0][impTP][0] = 0;
        }

        for (int i = 1; i < n; i++) {
                if (nums[i] == 0) {
                        for (int j = 0; j <= impTP; j++) {
                                dp[i][j][0] = min(dp[i-1][j][0], min(dp[i-1][j][1] + 1, dp[i][j][0]));
                                if (j != 0) {
                                        dp[i][j-1][1] = min(dp[i-1][j][1], min(dp[i-1][j][0] + 1, dp[i][j-1][1]));
                                }
                        }
                } else {
                        for (int j = 0; j <= impTP; j++) {
                                if (nums[i] == 1) {
                                        dp[i][j][1] = min(dp[i-1][j][1], min(dp[i][j][1], dp[i-1][j][0] + 1));
                                } else {
                                        dp[i][j][0] = min(dp[i-1][j][0], min(dp[i][j][0], dp[i-1][j][1] + 1));
                                }
                        }
                }
        }

        printf("%d", min(dp[n-1][0][0], dp[n-1][0][1]));
}
