#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, r, c;
int getNumber(int, int, vector<string>);
bool visited[25][25];
int main() {
    cin >> t;
    string line;
    for (int i = 0; i < t; i++) {
        vector<string> map;
        cin >> r >> c;
        for (int j = 0; j < r; j++) {
            cin >> line;
            map.push_back(line);
        }
        cout << getNumber(r, c, map) << endl;
    }
    
    return 0;
}
bool isValid(int row, int col, vector<string> map) {
    if (row >= r || row < 0 || col >= c || col < 0 || map[row][col] == '*' || visited[row][col]) {
        return false;
    }
    return true;
}
int getNumber(int rows, int cols, vector<string> map) {
    if (map[rows-1][cols-1] == '*') {
        return -1;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = false;
        }
    }
    queue<pair<pair<int, int>, int>> current;
    int count = 0;
    current.push({{0, 0}, 1});
    while (!current.empty()) {
        count++;
        pair<pair<int, int>, int> sec = current.front();
        current.pop();
        int row = sec.first.first;
        int col = sec.first.second;
        int moves = sec.second;
        if (visited[row][col]) {
            continue;
        }
        visited[row][col] = true;
        if (row == rows-1 && col== cols-1) {
            return sec.second;
        }
        if (map[row][col] == '|' || map[row][col] == '+') {
            if (isValid(row+1, col, map)) {
                current.push({{row + 1, col}, moves+1});
            }
            if (isValid(row-1, col, map)) {
                current.push({{row - 1, col}, moves+1});
            }
        }
        if (map[row][col] == '-' || map[row][col] == '+') {
            if (isValid(row, col+1, map)) {
                current.push({{row, col+1}, moves+1});
            }
            if (isValid(row, col-1, map)) {
                current.push({{row, col-1}, moves+1});
            }
        }
    }
    return -1;
}
