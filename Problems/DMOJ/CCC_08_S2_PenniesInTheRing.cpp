#include <iostream>
#include <cmath>

using namespace std;

long long pennies(int);
int main() {
    int radius;
    while (true) {
        cin >> radius;
        if (radius == 0) {
            break;
        }
        cout << pennies(radius) << endl;
    }
    return 0;
}
int getJ(int x, int radius) {
    double value = radius*radius - x*x;
    return sqrt(value);
}
long long pennies(int radius) {
    long long count = 0;
    for (int i = radius-1; i > 0; i--) {
        int j = getJ(i, radius);
        count += j;
    }
    count *= 4;
    count += (1 + radius*4);
    return count;
}
