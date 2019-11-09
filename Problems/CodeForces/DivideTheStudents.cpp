#include <iostream>

using namespace std;

int t, a, b, c;
int getOptimalDistribution(int, int, int, int);
int main() {
    ios_base::sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> c >> b;
        int currentMin = 10000000;
        for (int i = -c; i <= a; i++) {
            currentMin = min(currentMin, getOptimalDistribution(a, b, c, i));
        }
        printf("%i\n", currentMin);
    }
    return 0;
}
int getOptimalDistribution(int a, int b, int c, int x) {
    a -= x;
    if (x > 0) {
        int canGiveToB = c;
        c += x;
        if (c > b) {
            int giveToB = min((c-b + ((c-b)%2))/2 , canGiveToB);
            b += giveToB; c -= giveToB;
        }
    } else {
        c += x;
        if (b >= c) {
            int giveToC = min((b-c + ((c-b)%2))/2, b);
            c += giveToC; b -= giveToC;
        } else {
            int giveToB = min((c-b + ((c-b)%2))/2, c);
            b += giveToB; c -= giveToB;
        }
    }
    return max(a, max(b, c));
}
