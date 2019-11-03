#include <iostream>
#include <vector>

using namespace std;

long long amount[26], want[26], multiplier;
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", have, need;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> have >> multiplier >> need;
    for (int i = 0; i < have.length(); i++) {
        int index = (int)ALPHABET.find(have[i]);
        string value = "";
        while (true) {
            if (i == have.length()-1) {break;}
            if (ALPHABET.find(have[i+1]) == string::npos) {
                value += have[i+1];
                i++;
            } else {break;}
        }
        if (value.length() == 0) {value = "1";}
        amount[index] += (stoi(value) * multiplier);
    }
    long long output = 10e16;
    for (int i = 0; i < need.length(); i++) {
        int index = (int)ALPHABET.find(need[i]);
        string value = "";
        while (true) {
            if (i == need.length()-1) { break; }
            if (ALPHABET.find(need[i+1]) == string::npos) {
                value += need[i+1];
                i++;
            } else { break; }
        }
        if (value.length() == 0) { value = "1"; }
        want[index] += stoi(value);
    }
    for (int i = 0; i < 26; i++) {
        if (want[i] == 0) {continue;}
        output = min(output, amount[i]/want[i]);
    }
    cout << output << endl;
    return 0;
}
