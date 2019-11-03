#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    string Y, P, ex = "ex", vowels = "aiou";
    cin >> Y >> P;
    if (Y[Y.length()-1] == 'e') {
        cout << (Y + "x" + P) << endl;
    } else {
        char last = Y[Y.length()-1];
        bool found = false;
        for (int i = 0; i < Y.length(); i++) {
            if (last == vowels[i]) {
                found = true;
                Y = Y.substr(0, Y.length() - 1);
                break;
            }
        }
        if (found) {
            cout << (Y + ex + P) << endl;
        } else {
            if (Y.length() >= 2) {
                if (Y.substr(Y.length() - 2, Y.length()) == "ex") {
                    cout << (Y.substr(0, Y.length() - 2) + ex + P) << endl;
                } else {
                    cout << (Y + ex + P) << endl;
                }
            } else {
                cout << (Y + ex + P) << endl;
            }
        }
    }
    
    return 0;
}
