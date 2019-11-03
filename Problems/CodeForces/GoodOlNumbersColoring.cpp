//Not on git
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, a, b;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        if (__gcd(a, b) == 1) { cout << "finite" << endl; }
        else {cout << "infinite" << endl;}
    }
    return 0;
}
