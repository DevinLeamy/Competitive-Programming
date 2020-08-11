class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string s = to_string(x);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return rev == s;
    }
};
