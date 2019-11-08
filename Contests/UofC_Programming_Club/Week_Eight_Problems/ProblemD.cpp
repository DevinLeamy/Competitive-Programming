#include <iostream>

using namespace std;

int main() {
    int N, H, P;
    cin >> N >> P;
    int currentMax = 0;
    int current = 0;
    for (int i = 0; i < N; i++) {
        cin >> H;
        H -= P;
        current = max(H, current+H);
        currentMax = max(current , currentMax);
    }
    cout << currentMax << endl;
    return 0;
}
