#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> toBaseThree(long long);
int main() {
    int q;
    long long n;
    cin >> q;
    vector<long long> powersOfThree; powersOfThree.push_back(1);
    for (int i = 1; i <= 38; i++) { powersOfThree.push_back(3 * powersOfThree[i-1]);}
    for (int i = 0; i < q; i++) {
        cin >> n;
        long long temp = n;
        vector<int> baseThree = toBaseThree(n);
        int latest = -1;
        for (int j = 0; j < baseThree.size(); j++) {
            if (baseThree[j] == 2) { baseThree[j]++; temp += powersOfThree[j];}
            if (baseThree[j] == 3) {
                latest = j;
                baseThree[j] = 0;
                if (j+1 != baseThree.size()) { baseThree[j+1]++;}
                else { baseThree.push_back(1); }
            }
        }
        if (latest == -1) { cout << n << endl; }
        else {
            for (int j = 0; j < latest; j++) {
                if (baseThree[j] == 1) {
                    temp -= powersOfThree[j];
                }
            }
            cout << temp << endl;
            
        }
    }
    return 0;
}
vector<int> toBaseThree(long long num) {
    vector<int> result;
    while (num > 0) {
        result.push_back(num % 3);
        num /= 3;
    }
    return result;
}
