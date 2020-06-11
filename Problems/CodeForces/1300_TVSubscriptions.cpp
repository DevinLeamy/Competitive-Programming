#include <iostream>
using namespace std;

int main() {
    int t, n, k, d, a;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k >> d;
        int shows[n+1];
        int watching[1000001]= {0};

        for (int j = 0; j < n; j++) {
            cin >> a;
            shows[j] = a;
        }
        int last = 0;
        int count = 0;
        for (int z = 0; z < d; z++) {
            watching[shows[z]]++;
            if (watching[shows[z]] == 1) {
                count++;
            }
        }
        int output = count;
        for (int j = d; j < n; j++) {
            watching[shows[last]]--;
            if (watching[shows[last]] == 0){
                count--;
            }
            watching[shows[j]]++;
            if (watching[shows[j]] == 1) {
                count++;
            }
            output = min(output, count);
            last++;
        }
        cout << output << endl;
    }
    
    return 0;
}
//Too slow, O(N) rn
