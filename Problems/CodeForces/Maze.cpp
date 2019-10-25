#include <vector>
#include <iostream>
#include <deque>

using namespace std;
int r, c, k;
bool isValid(int, int);
int visited[501][501];
char canTravel[501][501];
void dfs(int, int);
int marker = 2;
int main() {
    int count = 0;
    scanf("%i%i%i", &r, &c, &k);
    vector<int> start;
    for (int i = 0; i < r; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < c; j++) {
            if (row[j] == '.' && start.size() == 0) {
                start.push_back(i);
                start.push_back(j);
            }
            if (row[j] == '.') {count++;}
            canTravel[i][j] = row[j];
            visited[i][j] = 0;
        }
    }
    visited[start[0]][start[1]] = 1;
    dfs(start[0], start[1]);
    for (int i = 0; i < r; i++) {
        string row = "";
        for (int j = 0; j < c; j++) {
//            cout << visited[i][j] << endl;
            if (visited[i][j] > count-k) {canTravel[i][j] = 'X';}
            row += canTravel[i][j];
        }
        cout << row << endl;
    }
    return 0;
}
void dfs(int row, int col) {
    if (isValid(row+1, col) && visited[row+1][col] == 0) {
        visited[row+1][col] = marker;
        marker++;
        dfs(row+1, col);
    }
    if (isValid(row-1, col) && visited[row-1][col] == 0) {
        visited[row-1][col] = marker;
        marker++;
        dfs(row-1, col);
    }
    if (isValid(row, col+1) && visited[row][col+1] == 0) {
        visited[row][col+1] = marker;
        marker++;
        dfs(row, col+1);
    }
    if (isValid(row, col-1) && visited[row][col-1] == 0) {
        visited[row][col-1] = marker;
        marker++;
        dfs(row, col-1);
    }
}
bool isValid(int row, int col) {
    if (row < r && row >= 0 && col < c && col >= 0 && canTravel[row][col] == '.') {
        return true;
    }
    return false;
}

