#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k, n;
    string s, t;
    cin >> k;
    for (int i = 0; i < k; i++) {
        bool works = true;
        bool switched = false;
        cin >> n >> s >> t;
        for (int j = 0; j < n; j++) {
            if (t[j] != s[j]) {
                if (switched) {
                    works = false;
                    break;
                }
                switched = true;
                char wants = t[j];
                char has = s[j];
                bool found = false;
                for (int z = j+1; z < n; z++) {
                    if (t[z] != s[z]) {
                        if (t[z] == wants && s[z] == has) {
                            s[z] = t[z];
                            found = true;
                            break;
                        } else {
                            works = false;
                            break;
                        }
                    }
                }
                if (!found) {
                    works = false;
                }
            }
        }
        if (works) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}
