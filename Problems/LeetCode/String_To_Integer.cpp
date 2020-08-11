class Solution {
public:
    int myAtoi(string str) {
        string output = "";
        bool flag = true;
        bool neg = false;
        for (int i = 0; i < str.length(); i++) {
            int val = str[i] - '0';
            if (flag && str[i] == ' ') continue;
            if (flag && str[i] == '-') {
                flag = false;
                neg = true;
            } else if (flag && str[i] == '+') {
                flag = false;
            } else if (val < 10 && val > -1) {
                flag = false;
                output += str[i];
            } else {
                break;
            }
        }
        int size = 0;
        for (int i = 0; i < output.size(); i++) {
            if (output[i] != '0') break;
            size++;
        }
        if (output == "") return 0;
        if (output.length() - size > 10) return (neg)? INT_MIN : INT_MAX;
        long long res = stoll(output) * (neg? -1: 1);
        if (res > INT_MAX) return INT_MAX;
        if (res < INT_MIN) return INT_MIN;
        return res;
    }
};
