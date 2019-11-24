#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t, n, q;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        bool possible = true;
        string output = "";
        int current = 0;
        vector<int> missingValues;
        for (int j = 0; j < n; j++) {
            cin >> q;
            if (q != current) {
                for (int z = current+1; z < q; z++) {
                    missingValues.push_back(z);
                }
                output += to_string(q) + " ";
                current = q;
            } else {
                if (missingValues.size() == 0 || q < current) {
                    possible = false;
                } else {
                    output += to_string(missingValues.back()) + " ";
                    missingValues.pop_back();
                }
            }
        }
        if (possible) {
            cout << output << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
