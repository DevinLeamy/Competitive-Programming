#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t, n;
    string pin;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        map<string, int> pins;
        vector<string> pinsInOrder;
        for (int j = 0; j < n; j++) {
            cin >> pin;
            pinsInOrder.push_back(pin);
            if (pins.count(pin)) {
                pins.at(pin)++;
            } else {
                pins.insert({pin, 1});
            }
        }
        int count = 0;
        for (auto itr = pins.begin(); itr != pins.end(); ++itr) {
            count += itr -> second -1;
        }
        cout << count << endl;
        for (string value : pinsInOrder) {
            if (pins.at(value) > 1) {
                int current = 0;
                while (true) {
                    string temp = value;
                    bool found = false;
                    for (int z = 0; z < 10; z++) {
                        temp[current] = to_string(z)[0];
                        if (!pins.count(temp)) {
                            pins.insert({temp, 1});
                            cout << temp << endl;
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    } else {
                        current++;
                    }
                }
                pins.at(value)--;
            } else {
                cout << value << endl;
            }
        }
    }
    return 0;
}
