#include <iostream>

using namespace std;


int main() {
    int a, b;
    scanf("%i%i", &a, &b);
    if (b < a || b - a > 1) {
        if (a == 9 && b == 1) {
            cout << a << 9 << " " << b << 0 << 0 << endl;
        } else {
            cout << -1 << endl;
        }
    } else {
        if (a == b) {
            cout << a << 0 << " " << b << 1 << endl;
        } else {
            cout << a << 9 << " " << b << 0 << endl;
        }
    }
    return 0;
}
