#include <iostream>
#include <vector>
using namespace std;

int q, n;
string s;

int main() {
    scanf("%i", &q);
    for (int i = 0; i < q; i++) {
        int count = 0;
        scanf("%i", &n);
        int ones = 0;
        int zeros = 0;
        vector<int> sizes;
        for (int z = 0; z < n; z++) {
            cin >> s;
            sizes.push_back((int)s.length());
            for (int j = 0; j < s.length(); j++) {
                if (s[j] == '0') {
                    zeros += 1;
                } else {
                    ones += 1;
                }
            }
        }
        sort(sizes.begin(), sizes.end());
        for (int size : sizes) {
            while (size > 1) {
                if (ones > zeros && ones > 1) {
                    ones -= 2;
                    size -= 2;
                } else if (zeros > 1) {
                    size -= 2;
                    zeros -= 2;
                } else {
                    break;
                }
            }
            if (size == 1) {
                size--;
                if (zeros % 2 == 1 && zeros >= 1) {
                    zeros--;
                } else if (ones % 2 == 1 && ones >= 1) {
                    ones--;
                } else {
                    if (zeros >= 1){
                        zeros -= 1;
                    } else {
                        ones -= 1;
                    }
                }
            }
            if (size == 0) {count++; }
        }
        cout << count << endl;
    }
    
    return 0;
}
