#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string num;
    cin >> num;
    vector<string> potential;
    int i = (int)num.length() -1;
    string good = "";
    while (i >= 0) {
        string ones = string(1, num[i]);
        if (stoi(ones) % 2 == 1) {i--; continue;}
        else if (stoi(ones) % 8 == 0) {good = ones; break;}
        int j = i-1;
        while (j >= 0) {
            string twos = string(1, num[j]) + ones;
            if (stoi(twos) % 4 != 0) {j--; continue;}
            else if (stoi(twos) % 8 == 0) {good = twos; break;}
            int z = j-1;
            while (z >= 0) {
                string threes = string(1, num[z]) + twos;
                if (stoi(threes) % 8 == 0) {good = threes; break;}
                z--;
            }
            if (good.length() > 0) {break;}
            j--;
        }
        if (good.length() > 0) {break;}
        i--;
    }
    if (good.length() > 0) {cout << "YES" << "\n" << good << endl;}
    else {cout << "NO" << endl;}
    return 0;
}
