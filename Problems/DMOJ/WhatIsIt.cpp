#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    long long a;
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool isGeo = true;
        bool isArth = true;
        vector< long long> values;
        double difference = -1;
        double mult = -1;
        for (int j = 0; j < 10; j++) {
            cin >> a;
            if (j > 1) {
                if (a != values[j-1]*mult) {
                    isGeo = false;
                }
                if (a != values[j-1] + difference) {
                    isArth = false;
                }
            }
            values.push_back(a);
            if (j == 1) {
                if (values[0] != 0) {
                    mult = values[1] / values[0];
                } else {
                    mult = 0;
                }
                difference = values[1] - values[0];
            }
        }
        if (isArth && isGeo) {
            cout << "both" << endl;
        } else if (isArth) {
            cout << "arithmetic" << endl;
        } else if (isGeo) {
            cout << "geometric" << endl;
        } else {
            cout << "neither" << endl;
        }
    }
    
    return 0;
}
