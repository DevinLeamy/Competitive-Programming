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
int winningOutComes = 0;
void recure(int currentRow, int currentCol, vector<int> scores, int t, vector<vector<bool>> played) {
	if (currentCol == 4) {
		currentRow++; currentCol = 0;
	}
	if (currentRow == 4) {
		int largest = -1; int count = 0;
		loopX(4) {largest = max(largest, scores[i]);}
		loopX(4) {if (scores[i] == largest) {count++;}}
		if (count == 1 && scores[t] == largest) {winningOutComes++;}
		return;
	}
	if (played[currentRow][currentCol] || currentRow == currentCol) {
		recure(currentRow, currentCol+1, scores, t, played);
	} else {
		played[currentRow][currentCol] = true;
		played[currentCol][currentRow] = true;
		scores[currentRow] += 3;
		recure(currentRow, currentCol+1, scores, t, played);
		scores[currentRow] -= 3; scores[currentCol] += 3;
		recure(currentRow, currentCol+1, scores, t, played);
		scores[currentRow]++; scores[currentCol] -= 2;
		recure(currentRow, currentCol+1, scores, t, played);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, g, a, b, sa, sb; cin >> t >> g; t--;
	vector< vector<bool> > played; vector<int> currentScore = {0, 0, 0, 0};
	for (int i = 0; i < 4; i++) {
		played.pb(vector<bool>());
		for (int j = 0; j < 4; j++) {
			played[i].pb(false);
		}
	}
	loopX(g) {
		cin >> a >> b >> sa >> sb;
		played[a-1][b-1] = true; played[b-1][a-1] = true;
		if (sa > sb) {currentScore[a-1] += 3;}
		else if (sb > sa) {currentScore[b-1] += 3;}
		else {currentScore[a-1]++; currentScore[b-1]++;}
	}
	recure(0, 0, {currentScore[0], currentScore[1], currentScore[2], currentScore[3]}, t, played);
	cout << winningOutComes << endl;
	return 0;
}
