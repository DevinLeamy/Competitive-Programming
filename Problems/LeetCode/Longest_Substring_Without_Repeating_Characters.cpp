#include <iostream>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> contains(200);
        for (int i = 0; i < 200; i++) {
            contains[i] = -1;
        }
        int ans = 0;
        int cur = 0;
        for (int i = 0; i < s.length(); i++) {
            int index = s[i] - ' ';
            if (contains[index] != -1) {
                cur = i - contains[index] - 1;
                for (int j = 0; j < 200; j++) {
                    if (contains[j] != -1 && contains[j] < contains[index]) {
                        contains[j] = -1;
                    }
                }
            }
            cur++;
            contains[index] = i;
            ans = max(ans, cur);
        }
        return ans;
    }
};
