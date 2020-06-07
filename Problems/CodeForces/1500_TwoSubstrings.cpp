#include <iostream>
 
using namespace std;
 
int dp[100001];
int main() {
    ios_base::sync_with_stdio(0);
    string line;
    cin >> line;
    char last = ' ';
    int countAB = 0;
    int countBA = 0;
    for (int i = 0; i < line.length(); i++) {
        if (last == 'B' && line[i] == 'A') {
            dp[i-1] = 2;
            dp[i] = 2;
            countBA++;
        }
        last = line[i];
    }
    last = ' ';
    bool can = false;
    int overlap = 0;
    for (int i = 0; i < line.length(); i++) {
        if (last == 'A' && line[i] == 'B') {
            if (dp[i] == 2 || dp[i-1] == 2) {
                overlap++;
            }
            countAB++;
        }
        last = line[i];
    }
    if (countAB > 0 && countBA > 0 && (countAB + countBA - overlap) > 1) {can = true;}
    countAB = 0;
    overlap = 0;
    countBA = 0;
    last = ' ';
    bool again = false;
    for (int i = 0; i < line.length(); i++) {
        dp[i] = 0;
        if (last == 'A' && line[i] == 'B') {
            dp[i-1] = 2;
            dp[i] = 2;
            countAB++;
        }
        last = line[i];
    }
    last = ' ';
    for (int i = 0; i < line.length(); i++) {
        if (last == 'B' && line[i] == 'A') {
            if (dp[i] == 2 || dp[i-1] == 2) {
                overlap++;
            }
            countBA++;
        }
        last = line[i];
    }
    if (countAB > 0 && countBA > 0 && (countAB + countBA - overlap) > 1) {again = true;}
    if (can && again) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
