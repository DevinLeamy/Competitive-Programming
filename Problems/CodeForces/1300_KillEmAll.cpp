#include <iostream>

using namespace std;

int main() {
    int q, n, r, x;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> r;
        int pos[n];
        int distance = 0;
        int last = 0;
        for (int j = 0; j < n; j++) {
            cin >> x;
            pos[j] = x;
        }
        sort(pos, pos + n);
        int count = 0;
        int current = n-1;
        while (current != -1) {
            int back = pos[current];
            if (back == last) {
                current--;
                continue;
            } else {
                if (back <= distance) {
                    current--;
                } else {
                    count++;
                    current--;
                    distance += r;
                    last = back;
                }
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
