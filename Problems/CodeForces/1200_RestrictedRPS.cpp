#include <iostream>

using namespace std;

int main() {
    int t, n, a, b, c;
    string seq;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> a >> b >> c >> seq;
        int wins = 0;
        char output[n];
        for (int j = 0; j < n; j++) {
            if (seq[j] == 'R' && (b > 0)) {
                    b--;
                    output[j] = 'P';
                    wins++;
            } else if (seq[j] == 'P' && (c > 0)) {
                    c--;
                    output[j] = 'S';
                    wins++;
            } else if (seq[j] == 'S' && a > 0) {
                a--;
                output[j] = 'R';
                wins++;
            } else {
                output[j] = ' ';
            }
        }
        string game = "";
        for (int j = 0; j < n; j++) {
            if (output[j] == ' ') {
                if (a > 0) {
                    a--;
                    game += 'R';
                } else if (b > 0) {
                    b--;
                    game += 'P';
                } else {
                    c--;
                    game += 'S';
                }
            } else {
                game += output[j];
            }
        }
        if (wins >= (n/2) + (n%2)) {
            cout << "YES" << endl;
            cout << game << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
