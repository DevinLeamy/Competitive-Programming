#include <iostream>

using namespace std;

bool isBananaWord(string);

int main() {
    while (true) {
        string word;
        cin >> word;
        if (word == "X") {
            break;
        }
        bool isMonkeyWord = isBananaWord(word);
        if (isMonkeyWord) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
bool isBananaWord(string word) {
    int open = 0;
    bool nextIsN = false;
    bool found = false;
    for (int i = 0; i < word.length(); i++) {
        if (nextIsN) {
            if (word[i] == 'N') {
                nextIsN = false;
            } else if (word[i] == 'S') {
                if (open > 0 && found) {
                    open--;
                    if (open == 0) {
                        found = false;
                    }
                } else {
                    return false;
                }
            } else {
                return false;
            }
            continue;
        }
        if (word[i] == 'A') {
            if (open > 0) {
                found = true;
            }
            nextIsN = true;
        } else if (word[i] == 'B') {
            open++;
        } else {
            return false;
        }
    }
    if (open > 0) {
        return false;
    }
    return true;
}


