class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector< vector<char> > ans;
        for (int j = 0; j < numRows; j++) {
            ans.push_back(vector<char>());
            for (int i = 0; i < s.length(); i++) {
                ans[j].push_back('_');
            }
        }
        int curRow = 0;
        int curCol = 0;
        bool down = false;
        for (int i = 0; i < s.length(); i++) {
            ans[curRow][curCol] = s[i];
            if (curRow == numRows - 1 || down == true) {
                curRow--;
                curCol++;
                down = true;
            }  else {
                curRow++;
            }
            if (curRow == 0) {
                down = false;
            }
        }
        string res = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < s.length(); j++) {
                if (ans[i][j] != '_') {
                    res += ans[i][j];
                }
            }
        }
        return res;
    }
};
