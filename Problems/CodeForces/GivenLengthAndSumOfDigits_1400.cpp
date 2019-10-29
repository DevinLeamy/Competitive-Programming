#include <iostream>
 
using namespace std;
 
int minimum[1001], maximum[1001];
int main() {
    ios_base::sync_with_stdio(0);
    int m, s;
    cin >> m >> s;
    if (s > m*9 || (s == 0 && m > 1)) { cout << "-1 -1" << endl; }
    else {
        int minD = s; int maxD = s;
        minimum[0] = 1; minD--; int currentMin = m-1;
        int currentMax = 0;
        int temp = m;
        while (temp > 0) {
            minimum[currentMin] += min(9, minD);
            minD -= minimum[currentMin];
            currentMin--;
            maximum[currentMax] += min(9, maxD);
            maxD -= maximum[currentMax];
            currentMax++;
            temp--;
        }
        string outputMin = "";
        string outputMax = "";
        for (int i = 0; i < m; i++) {
            outputMin += to_string(minimum[i]);
            outputMax += to_string(maximum[i]);
        }
        cout << outputMin << " " << outputMax << endl;
    }
    return 0;
}
