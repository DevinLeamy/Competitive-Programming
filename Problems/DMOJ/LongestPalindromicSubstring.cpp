#include <iostream>

using namespace std;

string findString(string s) {
    if (s.length() == 0) {
        return "";
    }
    int longest = 1;
    string pal = s.substr(0, 1);
    for (int i = 1; i < s.length(); i++) {
        if (s[i-1] == s[i]) {
            int currentTop = i;
            int currentBottom = i-1;
            int len = 2;
            while (true) {
                if (currentBottom - 1 >= 0 && currentTop+1 < s.length() && s[currentTop+1] == s[currentBottom-1]) {
                    currentTop++;
                    currentBottom--;
                    len += 2;
                } else {
                    break;
                }
            }
            string currentString = s.substr(currentBottom, len);
            if (currentString.length() > longest) {
                longest = currentString.length();
                pal = currentString;
            }
        }
        if (i != s.length()-1 && s[i-1] == s[i+1]) {
            int currentTop = i+1;
            int currentBottom = i-1;
            int len = 3;
            while (true) {
                if (currentBottom - 1 >= 0 && currentTop+1 < s.length() && s[currentTop+1] == s[currentBottom-1]) {
                    currentTop++;
                    currentBottom--;
                    len += 2;
                } else {
                    break;
                }
            }
            string currentString = s.substr(currentBottom, len);
            if (currentString.length() > longest) {
                longest = currentString.length();
                pal = currentString;
            }
        }
    }
    return pal;
}

int main(){
    string input;
    cin >> input;
    cout << findString(input) << endl;
    return 0;
}
