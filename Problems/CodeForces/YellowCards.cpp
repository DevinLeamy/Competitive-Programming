#include <iostream>

using namespace std;

int main() {
    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int cardsThatCanBeThrown = 0;
    cardsThatCanBeThrown += a1 * (k1-1);
    cardsThatCanBeThrown += a2 * (k2 - 1);
    int minimum = max(0, n - cardsThatCanBeThrown);
    int maximum = 0;
    if (k2 >= k1) {
        maximum += min(a1, n / k1);
        n -= maximum * k1;
        maximum += min(a2, n / k2);
    } else {
        maximum += min(a2, n/k2);
        n -= maximum * k2;
        maximum += min(a1, n / k1);
    }
    cout << minimum << " " << maximum << endl;
    
    
    return 0;
}
