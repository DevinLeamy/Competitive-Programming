#include <iostream>

using namespace std;

int main() {
    long long T, n, l, r;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n >> l >> r;
        long long minimum = r;
        long long maximum = l;
        for (int j = 0; j < n-1; j++) {
            cin >> l >> r;
            minimum = min(minimum, r);
            maximum = max(maximum, l);
        }
        if (maximum - minimum <= 0) {
            cout << 0 << endl;
        } else {
            cout << (maximum - minimum) << endl;
        }
    }
    
    return 0;
}
