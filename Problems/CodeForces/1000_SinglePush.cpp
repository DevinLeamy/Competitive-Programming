#include <iostream>

using namespace std;

int arrayA[100001], arrayB[100001];
int main() {
    int t, n, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        
        for (int j = 0; j < n; j++) {
            cin >> a;
            arrayA[j] = a;
        }
        for (int j = 0; j < n; j++) {
            cin >> b;
            arrayB[j] = b;
        }
        bool works = true;
        int difference = -1;
        int start = 0;
        for (int j = 0; j < n; j++) {
            if (arrayA[j] != arrayB[j]) {
                difference = arrayB[j] - arrayA[j];
                if (difference <= 0) {
                    works = false;
                }
                break;
            }
            start = j;
        }
        int index = n;
        for (int j = start+1; j < n; j++) {
            if (arrayB[j] - arrayA[j] != difference) {
                index = j;
                break;
            }
        }
        for (int j = index; j < n; j++) {
            if (arrayA[j] != arrayB[j]) {
                works = false;
                break;
            }
        }
        
        if (works) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
