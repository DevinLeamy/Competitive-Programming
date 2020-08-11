class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            char cur = s[i];
            char next = '_';
            if (i != s.length()-1) {
                next = s[i+1];
            }
            if (cur == 'I') {
                if (next == 'V' || next == 'X') {
                    ans--;
                } else {
                    ans++;
                }
            } else if (cur == 'V') {
                ans += 5;
            } else if (cur == 'X') {
                if (next == 'L' || next == 'C') {
                    ans -= 10;
                } else {
                    ans += 10;
                }
            } else if (cur == 'L') {
                ans += 50;
            } else if (cur == 'C') {
                if (next == 'D' || next == 'M') {
                    ans -= 100;
                } else {
                    ans += 100;
                }
            } else if (cur == 'D') {
                ans += 500;
            } else if (cur == 'M') {
                ans += 1000;
            } 
        }
        return ans;
    }
};
