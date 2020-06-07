#include <iostream>

using namespace std;

long long rocks[(int) 10e5 + 7];
long long sorted[(int)10e5 + 7];
int main() {
    int l, r, n, v, m, t;
    scanf("%i", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%i", &v);
        rocks[i] = sorted[i] = v;
    }
    sort(sorted, sorted + n+1);
    for (int i = 1; i <= n; i++) {
        rocks[i] += rocks[i-1];
        sorted[i] += sorted[i-1];
    }
    scanf("%i", &m);
    for (int i = 0; i < m; i++) {
        scanf("%i%i%i", &t, &l, &r);
        if (t == 1) {
            cout << (rocks[r] - rocks[l-1]) << endl;
        } else {
            cout << (sorted[r] - sorted[l-1]) << endl;
        }
    }
    return 0;
}
