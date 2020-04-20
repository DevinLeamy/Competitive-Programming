#include <stdio.h>
#include <string.h>

int main() {
        int n;
        scanf("%d", &n);
        char s[n];
        scanf("%s", s);
        char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
        int cur = 25;
        int deleted = 0;
        while(cur != 0 && (n - deleted) != 1) {
                int found = 0;
                for (int i = 0; i < (n - deleted); i++) {
                        if (alphabet[cur] == s[i]) {
                                if (i != (n - deleted) - 1) {
                                        if (alphabet[cur-1] == s[i+1]) {
                                                for (int j = i; j < n-1; j++) {
                                                        s[j] = s[j+1];
                                                }
                                                s[n - deleted - 1] = '\0';
                                                found = 1;
                                                deleted += 1;
                                                continue;
                                        }
                                }
                                if (i != 0) {
                                        if (alphabet[cur-1] == s[i-1]) {
                                                for (int j = i; j < n-1; j++) {
                                                        s[j] = s[j+1];
                                                }
                                                s[n - deleted - 1] = '\0';
                                                found = 1;
                                                deleted += 1;
                                                continue;
                                        }
                                }
                        }
                }

                if (found == 0) {
                        cur -= 1;
                }
        }
        printf("%d", deleted);
}
