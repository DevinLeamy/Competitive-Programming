class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        for (int i = 1000; i >= 1; i /= 10) {
            int div = num / i;
            num -= i * div;
            if (i == 1000) {
                for (int j = 0; j < div; j++) {
                    ans += "M";
                }
            } else if (i == 100) {
                if (div == 9) {
                    ans += "CM";
                } else if (div == 4) {
                    ans += "CD";
                } else {
                    if (div >= 5) {
                        ans += "D";
                        div -= 5;
                    }
                    for (int i = 0; i < div; i++) {
                        ans += "C";
                    }
                }
            } else if (i == 10) {
                if (div == 9) {
                    ans += "XC";
                } else if (div == 4) {
                    ans += "XL";
                } else {
                    if (div >= 5) {
                        ans += "L";
                        div -= 5;
                    }
                    for (int i = 0; i < div; i++) {
                        ans += "X";
                    }
                }
            } else {
                if (div == 9) {
                    ans += "IX";
                } else if (div == 4) {
                    ans += "IV";
                } else {
                    if (div >= 5) {
                        ans += "V";
                        div -= 5;
                    }
                    for (int i = 0; i < div; i++) {
                        ans += "I";
                    }
                }
            }
        }
        return ans;
    }
};
