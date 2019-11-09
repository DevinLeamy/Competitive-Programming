#include <iostream>
 
using namespace std;
 
int q, n;
long long k;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> n >> k; int count = 0;
        string line, output = ""; cin >> line;
        for (int i = 0; i < n; i++) {
            if (line[i] == '0' && k > 0) {
                int moves = (int)min(k, (long long)count);
                output += '1';
                output[i-moves] = '0';
                k -= moves;
            } else {count++; output += line[i];}
        }
        printf("%s\n", output.c_str());
    }
    return 0;
}
