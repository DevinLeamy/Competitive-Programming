#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, r, g, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> r >> g >> b;
        vector<long long> sweets = {r, g, b};
        sort(sweets.begin(), sweets.end());
        if (sweets[2] >= sweets[1] + sweets[0]) {
            cout << (sweets[1] + sweets[0]) << endl;
        } else {
            cout << (r + g + b)/2 << endl;
        }
    }
    return 0;
}
