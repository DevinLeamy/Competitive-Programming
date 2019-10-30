#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, h, initial = 0;
    cin >> n;
    vector<int> game(n);
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (h == 1) {initial++;}
        game[i] = h;
    }
    if (n == 1) {printf("%i", (1 - initial));}
    else {
        int output = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int count = 0;
                for (int z = i; z <= j; z++) {
                    if (game[z] == 0) {count++;}
                    else {count--;}
                }
                output = max(count, output);
            }
        }
        printf("%i", (output + initial));
    }
}
