//Not on github

#include <iostream>
#include <unordered_map>

using namespace std;

int n;
int main() {
    string line;
    scanf("%i", &n);
    string ALPHABET = "abcdefghijklmnopqrstuvwxyz";
    unordered_map<char, int> alphabetMap;
    for (int i = 25; i >= 0; i--) {
        alphabetMap[ALPHABET[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        bool works[26];
        for (int i = 0; i < 26; i++) {
            works[i] = false;
        }
        cin >> line;
        line += "_";
        int count = 1;
        char lastCharacter = line[0];
        for (int j = 1; j < line.length(); j++) {
            if (line[j] == lastCharacter) {
                count++;
            } else {
                if (count % 2 == 1) {
                    works[alphabetMap[lastCharacter]] = true;
                }
                count = 1;
            }
            lastCharacter = line[j];
        }
        string output = "";
        for (int i = 0; i < 26; i++) {
            if (works[i]) {
                output += ALPHABET[i];
            }
        }
        cout << output << endl;
    }
 
    return 0;
}
