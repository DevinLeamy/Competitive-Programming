#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    vector<int> start(n);
    vector<int> end(n);
    for (int i = 0; i < n; i++) { cin >> a; start[i] = a-1; }
    for (int i = 0; i < n; i++) { cin >> b; end[i] = b-1; }
    int count = 0, current = 0;
    vector<bool> counted(n);
    for (int num : start) { if (counted[num]) {continue;}
        while (true) {
            if (num == end[current]) {
                counted[num] = true;
                current++;
                break;
            }
            counted[end[current]] = true;
            current++; count++;
        }
    }
    cout << count << endl;
    return 0;
}
