#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int T, D, M, d;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> D >> M;
        int current = 7;
        vector<int> months(1001);
        for (int j = 0; j < M; j++) {
            cin >> d;
            months[j] = d;
        }
        int count = 0;
        int currentMonth = 0, dayOfMonth = 1;
        for (int j = 0; j < D; j++) {
            if (current == 5 && dayOfMonth == 13) {
                count++;
            }
            dayOfMonth++;
            if (dayOfMonth > months[currentMonth]) {
                currentMonth++;
                dayOfMonth = 1;
            }
            current++;
            current = current % 7;
        }
        cout << count << endl;
    }
    return 0;
}
