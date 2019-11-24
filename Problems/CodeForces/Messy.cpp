#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ()()()(()()())
//Misunderstood the problem
string s;
void flip(int);
int getIndex(int);
int main() {
    int t, n, k;
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k >> s;
        int opBra = 0;
        int count = 0;
        int last = 0;
        vector<pair<int, int>> reversals;
        for (int j = 0; j < n; j++) {
//            cout << s << endl;
            if (count == k-1) {
                last = j;
                break;
            }
            if (opBra > 0) {
                count++;
                if (s[j] == '(') {
                    reversals.push_back(make_pair(j, getIndex(j)));
                }
                opBra--;
            } else {
                opBra++;
                if (s[j] == ')') {
                    reversals.push_back(make_pair(j, getIndex(j)));
                }
            }
        }
        int current = last;
        while (current != n) {
//            cout << s << endl;
            if (current == n-1) {
                if (s[current] == '(') {
                    reversals.push_back(make_pair(current, getIndex(current)));
                }
                break;
            }
            if (opBra == 0) {
                if (s[current] == ')') {
                    reversals.push_back(make_pair(current, getIndex(current)));
                }
                opBra++;
            } else if (opBra == 1) {
                if (s[current] == ')') {
                    reversals.push_back(make_pair(current, getIndex(current)));
                }
                opBra++;
            } else {
                if (s[current] == '(') {
                    reversals.push_back(make_pair(current, getIndex(current)));
                }
                opBra--;
            }
            current++;
        }
        cout << reversals.size() << endl;
        for (pair<int, int> range : reversals) {
            cout << range.first+1 << " " << range.second+1 << endl;
        }
    }
    return 0;
}
int getIndex(int index) {
    char currentChar = s[index];
    int end = 0;
    string current = "";
    for (int i = index; i < s.length(); i++) {
        current += s[i];
        if (s[i] != currentChar) {
            end = i;
            break;
        }
    }
    reverse(current.begin(), current.end());
    for (int i = index; i <= end; i++) {
        s[i] = current[i-index];
    }
    return end;
}
void flip(int index) {
    if (s[index] == ')') {
        s[index] = '(';
    } else {
        s[index] = ')';
    }
}
