#include <iostream>
#include <vector>

using namespace std;



int main() {
    int k, n;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    cin >> k;
    for (int i = 0; i < k; i++) {
        string s, t;
        cin >> n >> s >> t;
        vector< vector<pair<char, int>> > swaps(26);
        vector<string> output;
        bool tried = false;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[j]) {
                int index = (int)alphabet.find(t[j]);
                int otherIndex = (int)alphabet.find(s[j]);
                if (swaps[index].size() > 0) {
                    if (tried) {
                        output.push_back(to_string(j+1) + " " + to_string(j+1));
                    }
                    int indexI = swaps[index][swaps[index].size()-1].second;
                    swaps[index].pop_back();
                    output.push_back(to_string(indexI+1) + " "  + to_string(j+1));
                    t[j] = s[indexI];
                    t[indexI] = s[indexI];
                    j--;
                    tried = false;
                } else if (swaps[otherIndex].size() > 0 && !tried){
                    char temp = t[j];
                    t[j] = s[j];
                    s[j] = temp;
                    j--;
                    tried = true;
                } else {
                    swaps[index].push_back(make_pair(t[j], j));
                    tried = false;
                }
            }
        }
        bool found = false;
        for (int j = 0; j < 26; j++) {
            if (swaps[j].size() > 0) {
                found = true;
            }
        }
        if (found) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            cout << output.size() << endl;
            for (string line : output) {
                cout << line << endl;
            }
        }
        
    }
    return 0;
}
