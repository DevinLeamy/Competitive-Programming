class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        string s = to_string(x);
        string ans = "";
        bool flag = true;
        for (int i = s.length()-1; i >= (neg)? 1:0; i--) {
            if (flag && s[i] == '0') {
                continue;
            } else {
                flag = false;
                ans += s[i];
            }
        }
        if (ans == "") return 0;
        long long res = stoll(((neg)? "-":"") + ans);
        if (res != (int)res) return 0;
        return res;
    }
};
