class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            bool works = true;
            for (int j = 1; j < strs.size(); j++) {
                if (c != strs[j][i]) {
                    works = false;
                    break;
                }
            }
            if (works) {
                ans += c;
            } else {
                break;
            }
        }
        return ans;
    }
};
