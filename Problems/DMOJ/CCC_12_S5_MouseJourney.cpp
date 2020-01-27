#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loopX(h) for(int i = 0; i < h; i++)

using namespace std;

int visited[26][26];
bool isValid(int,int,int,int);
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r, c, b, row, col; cin >> r >> c >> b;
	for (int i = 0; i < b; i++) {
		cin >> row >> col;
		visited[row-1][col-1] = -1;
	}
	visited[0][0] = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (visited[i][j] == -1) {continue;}
			if (isValid(r, c, i-1, j)) {visited[i][j] += (visited[i-1][j] == -1)? 0 : visited[i-1][j];}
			if (isValid(r, c, i, j-1)) {visited[i][j] += (visited[i][j-1] == -1)? 0 : visited[i][j-1];}
		}
	}
	cout << visited[r-1][c-1] << endl;
	return 0;
}
bool isValid(int rows, int cols, int row, int col) {
	if (row < rows && col < cols && row >= 0 && col >= 0) {return true;}
	return false;
}
