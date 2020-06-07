#include <iostream>
#include <bitset>
using namespace std;


int main() {
    int n, p;
    cin >> n >> p;
    if (p == 0) {
        string binary = bitset<32>(n).to_string();
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (binary[i] == '1') {
                count++;
            }
        }
        cout << count << endl;
    } else {
        int temp = n;
        int count = 1;
        while (true) {
            temp -= p;
            if (temp <= 0 || temp < count) {count = -1;break;}
            string binary = bitset<32>(temp).to_string();
            int bits = 0;
            for (int i = 0; i < 32; i++) {
                if (binary[i] == '1') {
                    bits++;
                }
            }
            if (bits > count) {count++; continue;}
            else {break;}
            
        }
        cout << count << endl;
    }
    
    return 0;
}
