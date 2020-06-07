#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, h, initial = 0;
    cin >> n;
    int output = -1, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        sum = max(((h==0)? 1 : -1), sum + ((h==0)? 1 : -1));
        output = max(sum, output);
        initial += ((h==0)? 0 : 1);
    }
    printf("%i", (output + initial));
}
