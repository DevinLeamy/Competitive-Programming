#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#define INF 2147483647;
#define LINF 9223372036854775807;
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
#define PI pair<int, int>
#define ll long long
#define pb push_back
#define loop(h) for(int i = 0; i < h; i++)
using namespace std;
char _;
int n, m;
vector<vector<int>> distances;
vector<vector<char>> grid;
vector<vector<bool>> visited;
void cameraSpot(int, int);
bool isValid(int, int);
int increment(int, int);
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m; string line;
	pair<int, int> start = {0, 0}; vector<PI> cameras;
	for (int i = 0; i < n; i++) {
		cin >> line;
		grid.pb(vector<char>()); distances.pb(vector<int>()); visited.pb(vector<bool>());
		for (int j = 0; j < m; j++) {
			grid[i].pb(line[j]);
			
			if (line[j] == 'W' || line[j] == 'C') {
				distances[i].pb(10000000);
				visited[i].pb(true);
				if (line[j] == 'C') {cameras.pb({i, j});}
			} else {
				if (line[j] == 'S') {start.first = i; start.second = j;}
				if (line[j] == '.') {distances[i].pb(1000000);}
				else { distances[i].pb(10000000);}
				visited[i].pb(false);
			}
		}
	}
	for (PI camera : cameras) {
		cameraSpot(camera.first, camera.second);
	}
	queue<pair<int, PI>> current; current.push({0, start});
	while (!current.empty()) {
		pair<int, PI> value = current.front(); current.pop();
		PI coords = value.second; int currentDistance = value.first;
		int row = coords.first, col = coords.second;
		if (visited[row][col] && increment(row, col) == 0) {continue;}
		else if (visited[row][col] && increment(row, col) == 1 && distances[row][col] <= currentDistance) {continue;}
		visited[row][col] = true;
		if (grid[row][col] == 'U') {
			if (isValid(row-1, col)) {
				current.push({currentDistance+increment(row-1, col), {row-1, col}});
			}
		} else if (grid[row][col] == 'D') {
			if (isValid(row+1, col)) {
				current.push({currentDistance+increment(row+1, col), {row+1, col}});
			}
		} else if (grid[row][col] == 'R') {
			if (isValid(row, col+1)) {
				current.push({currentDistance+increment(row, col+1), {row, col+1}});
			}
		} else if (grid[row][col] == 'L') {
			if (isValid(row, col-1)) {
				current.push({currentDistance+increment(row, col-1), {row, col-1}});
			}
		} else {
			if (grid[row][col] == '.') {
				distances[row][col] = min(distances[row][col], currentDistance);
			}
			if (isValid(row+1, col)) {
				current.push({currentDistance+increment(row+1, col), {row+1, col}});
			}
			if (isValid(row-1, col)) {
				current.push({currentDistance+increment(row-1, col), {row-1, col}});
			}
			if (isValid(row, col+1)) {
				current.push({currentDistance+increment(row, col+1), {row, col+1}});
			}
			if (isValid(row, col-1)) {
				current.push({currentDistance+increment(row, col-1), {row, col-1}});
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (distances[i][j] != 10000000) {
				if (distances[i][j] == 1000000) {
					cout << "-1" << endl;
				} else {
					cout << distances[i][j] << endl;
				}
			}
		}
	}
	return 0;
}
void cameraSpot(int row, int col) {
	for (int i = row; i < n; i++) {
		if (grid[i][col] == 'W') {break;}
		else if (grid[i][col] != 'U' && grid[i][col] != 'D' && grid[i][col] != 'L' && grid[i][col] != 'R'){
			visited[i][col] = true;
		}
	}
	for (int i = row; i >= 0; i--) {
		if (grid[i][col] == 'W') {break;}
		else if (grid[i][col] != 'U' && grid[i][col] != 'D' && grid[i][col] != 'L' && grid[i][col] != 'R'){
			visited[i][col] = true;
		}
	}
	for (int i = col; i < m; i++) {
		if (grid[row][i] == 'W') {break;}
		else if (grid[row][i] != 'U' && grid[row][i] != 'D' && grid[row][i] != 'L' && grid[row][i] != 'R'){
			visited[row][i] = true;
		}
	}
	for (int i = col; i >= 0; i--) {
		if (grid[row][i] == 'W') {break;}
		else if (grid[row][i] != 'U' && grid[row][i] != 'D' && grid[row][i] != 'L' && grid[row][i] != 'R'){
			visited[row][i] = true;
		}
	}
}
int increment(int row, int col) {
	if (grid[row][col] == '.') {return 1;}
	return 0;
}
bool isValid(int row, int col) {
	if (row >= n || row < 0 || col >= m || col < 0) {return false;}
	if ((visited[row][col] && increment(row, col) == 0) || (visited[row][col] && distances[row][col] == 1000000)) {
		return false;
	}
	return true;
}
